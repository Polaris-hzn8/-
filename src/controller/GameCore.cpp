///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "GameCore.h"
#include "utility/RandomUtil.h"

GameCore* GameCore::s_instance = nullptr;

GameCore* GameCore::getInstance()
{
    if (!s_instance) {
        s_instance = new GameCore();
    }
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
    while (m_bGameRuning) {
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
    if (curTime <= maxTime) {
        gameModel->setCurTime(curTime + 1);
    } else {
        finish();
    }

    // 刷新玩家存款与欠债数据
    GameRole* pRole = gameModel->getRole();
    // 更新存款数据
    int deposit = (int)pRole->GetDeposit() * 1.05f;
    pRole->SetDeposit(deposit);
    // 玩家欠债数据
    int debet = (int)pRole->GetDebt() * 1.1f;
    pRole->SetDebt(debet);

    // 遍历所有地铁站 并刷新每个地铁站中的黑市商品数据
    vector<RailStation*>* railStations = gameModel->getRailStations();
    for (RailStation* railStation : *railStations) {
        // 获取黑市对象
        BlackMarket* market = railStation->getMarket();
        // 刷新黑市数据
        MarketListUpdate(market);
    }


}

void GameCore::MarketListUpdate(BlackMarket* market)
{
    // 获取初始的物品数据
    map<int, GameItem*>* pGameItems = GameModel::getInstance()->getGameItems();

    // 随机产生的物品数量 5~7
    int itemNums = RandomUtil::getRandomInteger(5, 7);

    // 从初始物品数据中选择itemNums个数量的 物品记录到集合中 并保证不会有重复物品产生
    // (1) 随机生成randomItemIds
    vector<int> itemIds;
    for (int i = 0; i < pGameItems->size(); ++i) {
        itemIds.push_back(i + 1);
    }
    vector<int> randomItemIds;
    int i = 0;
    while (i < itemNums) {
        int minIndex = 0;
        int maxIndex = pGameItems->size() - 1;
        int randomIndex = RandomUtil::getRandomInteger(minIndex, maxIndex);
        randomItemIds.push_back(randomIndex);
        itemIds.erase(itemIds.begin() + randomIndex);
        i++;
    }
    
    // (2) 创建商品实例 随机生成的商品数据 存储到Market对象中
    vector<GameItem*>* itemList = market->getItemList();
    itemList->clear();
    for (int randomId : randomItemIds) {
        // 从GameModel中获取pGameItems
        GameItem* item = pGameItems->at(randomId);
        // 创建商品实例 与GameModel中的pGameItems不同
        GameItem* commodity = new GameItem();
        // 随机生成商品的今日价格
        int randomPrice = RandomUtil::getRandomInteger(item->GetMinPrice(), item->GetMaxPrice());
        // 设置商品数据
        commodity->SetId(item->GetId());
        commodity->SetName(item->GetName());
        commodity->SetOutPrice(randomPrice);
        itemList->push_back(commodity);
    }
}

/**
 * screenUpdate刷新游戏显示
 */
void GameCore::screenUpdate()
{
    GameModel* gameModel = GameModel::getInstance();
    GameViewer* gameViewer = GameViewer::getInstance();
    int curTime = gameModel->getCurTime();
    int maxTime = gameModel->getMaxTime();
    if (curTime > maxTime) {
        return;
    }
    gameViewer->startGameDisplay();
}




