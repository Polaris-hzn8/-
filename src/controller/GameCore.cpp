///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-03-26 22:57
/// @Mail		: 3453851623@qq.com
///****************************************************************************

#include <algorithm>
#include "GameCore.h"
#include "utility/RandomUtil.h"

GameCore* GameCore::s_instance = nullptr;

GameCore* GameCore::getInstance()
{
    if (!s_instance)
        s_instance = new GameCore();
    return s_instance;
}

GameCore::GameCore()
{
    m_bGameRuning = false;
}

GameCore::~GameCore()
{

}

// 游戏主循环
void GameCore::start()
{
    m_bGameRuning = true;
    while (m_bGameRuning)
    {
        logicUpdate();  // 逻辑刷新
        screenUpdate(); // 显示刷新
    }
}

void GameCore::finish()
{
    cout << "GameOver." << endl;
    m_bGameRuning = false;
}

/**
 * logicUpdate刷新游戏数据
 *  - 判定游戏是否结束
 *  - 刷新玩家存款与欠债数据
 *  - 刷新每日黑市商品数据
 */
void GameCore::logicUpdate()
{
    GameModel* gameModel = GameModel::getInstance();
    // 判定游戏是否结束
    int curTime = gameModel->getCurTime();
    int maxTime = gameModel->getMaxTime();
    if (curTime > maxTime)
    {
        finish();
    }
    // 刷新当前游戏时间
    gameModel->setCurTime(curTime + 1);
    // 刷新玩家存款与欠债数据
    GameRole* pRole = gameModel->getRole();
    // 刷新玩家存款数据
    int deposit = (int)pRole->GetDeposit() * 1.05f;
    pRole->SetDeposit(deposit);
    // 刷新玩家欠债数据
    int debet = (int)pRole->GetDebt() * 1.1f;
    pRole->SetDebt(debet);

    // 遍历所有地铁站 并刷新每个地铁站中的黑市商品数据
    vector<RailStation*>* railStations = gameModel->getRailStations();
    for (RailStation* railStation : *railStations)
    {
        // 获取黑市对象
        BlackMarket* market = railStation->getMarket();
        // 刷新黑市数据
        MarketListUpdate(market);
    }


}

/**
 * 黑市商品数据更新主要更新的数据包括
 * - 黑市物品的数量
 * - 单件物品的今日价格
 */
void GameCore::MarketListUpdate(BlackMarket* market)
{
    // 1.获取所有的物品数据
    map<int, GameItem*>* pGameItems = GameModel::getInstance()->getGameItems();
    // 随机产生黑市今日上架的商品数量(5~7件)
    int item_nums = RandomUtil::getRandomInteger(5, 7);
    // 从初始物品数据中随机挑选itemNums个物品数量 保存到集合中 并保证不会有重复商品被选中
    // 获取全部物品的id值保存到itemIds数组中
    vector<int> item_ids;
    for (int i = 0; i < pGameItems->size(); ++i)
        item_ids.push_back(i);
    // 从itemIds数组中随机挑选出黑市今日准备上架的商品id
    vector<int> item_ids_random;
    for (int i = 0; i < item_nums; ++i)
    {
        int idx_min = 0;
        int idx_max = item_ids.size() - 1;
        int idx_tmp = RandomUtil::getRandomInteger(idx_min, idx_max);
        item_ids_random.push_back(item_ids[idx_tmp]); // 被选中的id加入到集合中
        item_ids.erase(item_ids.begin() + idx_tmp);   // 抹除已经被选中的id
    }

    sort(item_ids_random.begin(), item_ids_random.end());
    
    // 2.根据已经挑选好的商品id随机生成价格 并存储到BlackMarket对象中
    vector<GameItem*>* market_item_list = market->getItemList();
    market_item_list->clear();
    for (int item_id : item_ids_random)
    {
        GameItem* item = pGameItems->at(item_id);
        GameItem* commodity = new GameItem();
        int commodity_price = RandomUtil::getRandomInteger(item->GetMinPrice(), item->GetMaxPrice());
        commodity->SetId(item->GetId());
        commodity->SetName(item->GetName());
        commodity->SetOutPrice(commodity_price);
        commodity->SetCount(100);
        market_item_list->push_back(commodity);
    }
}

/**
 * screenUpdate刷新游戏显示
 */
void GameCore::screenUpdate()
{
    GameModel* gameModel = GameModel::getInstance();
    GameMenuView* gameMenuView = GameMenuView::getInstance();
    int curTime = gameModel->getCurTime();
    int maxTime = gameModel->getMaxTime();
    if (curTime > maxTime)
        return;
    gameMenuView->startGameDisplay();
}




