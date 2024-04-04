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

// ��Ϸ��ѭ��
void GameCore::start()
{
    m_bGameRuning = true;
    while (m_bGameRuning)
    {
        logicUpdate();  // �߼�ˢ��
        screenUpdate(); // ��ʾˢ��
    }
}

void GameCore::finish()
{
    cout << "GameOver." << endl;
    m_bGameRuning = false;
}

/**
 * logicUpdateˢ����Ϸ����
 *  - �ж���Ϸ�Ƿ����
 *  - ˢ����Ҵ����Ƿծ����
 *  - ˢ��ÿ�պ�����Ʒ����
 */
void GameCore::logicUpdate()
{
    GameModel* gameModel = GameModel::getInstance();
    // �ж���Ϸ�Ƿ����
    int curTime = gameModel->getCurTime();
    int maxTime = gameModel->getMaxTime();
    if (curTime > maxTime)
    {
        finish();
    }
    // ˢ�µ�ǰ��Ϸʱ��
    gameModel->setCurTime(curTime + 1);
    // ˢ����Ҵ����Ƿծ����
    GameRole* pRole = gameModel->getRole();
    // ˢ����Ҵ������
    int deposit = (int)pRole->GetDeposit() * 1.05f;
    pRole->SetDeposit(deposit);
    // ˢ�����Ƿծ����
    int debet = (int)pRole->GetDebt() * 1.1f;
    pRole->SetDebt(debet);

    // �������е���վ ��ˢ��ÿ������վ�еĺ�����Ʒ����
    vector<RailStation*>* railStations = gameModel->getRailStations();
    for (RailStation* railStation : *railStations)
    {
        // ��ȡ���ж���
        BlackMarket* market = railStation->getMarket();
        // ˢ�º�������
        MarketListUpdate(market);
    }


}

/**
 * ������Ʒ���ݸ�����Ҫ���µ����ݰ���
 * - ������Ʒ������
 * - ������Ʒ�Ľ��ռ۸�
 */
void GameCore::MarketListUpdate(BlackMarket* market)
{
    // 1.��ȡ���е���Ʒ����
    map<int, GameItem*>* pGameItems = GameModel::getInstance()->getGameItems();
    // ����������н����ϼܵ���Ʒ����(5~7��)
    int item_nums = RandomUtil::getRandomInteger(5, 7);
    // �ӳ�ʼ��Ʒ�����������ѡitemNums����Ʒ���� ���浽������ ����֤�������ظ���Ʒ��ѡ��
    // ��ȡȫ����Ʒ��idֵ���浽itemIds������
    vector<int> item_ids;
    for (int i = 0; i < pGameItems->size(); ++i)
        item_ids.push_back(i);
    // ��itemIds�����������ѡ�����н���׼���ϼܵ���Ʒid
    vector<int> item_ids_random;
    for (int i = 0; i < item_nums; ++i)
    {
        int idx_min = 0;
        int idx_max = item_ids.size() - 1;
        int idx_tmp = RandomUtil::getRandomInteger(idx_min, idx_max);
        item_ids_random.push_back(item_ids[idx_tmp]); // ��ѡ�е�id���뵽������
        item_ids.erase(item_ids.begin() + idx_tmp);   // Ĩ���Ѿ���ѡ�е�id
    }

    sort(item_ids_random.begin(), item_ids_random.end());
    
    // 2.�����Ѿ���ѡ�õ���Ʒid������ɼ۸� ���洢��BlackMarket������
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
 * screenUpdateˢ����Ϸ��ʾ
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




