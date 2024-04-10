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
        finish();

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
    map<int, GameItem*>* pGameItemsMap = GameModel::getInstance()->getGameItems();
    int nTotalNums = pGameItemsMap->size();                                     // ������������
    int nPartialNums = nTotalNums / 2;                                          // �������������
    int nTodayNums = RandomUtil::getRandomInteger(nPartialNums, nTotalNums);    // ����������н����ϼܵ���Ʒ����
    
    // �ӳ�ʼ��Ʒ�����������ѡitemNums����Ʒ���� ���浽������ ����֤�������ظ���Ʒ��ѡ��
    // ��ȡȫ����Ʒ��idֵ���浽vctItemIds������
    vector<int> vctItemIds;
    for (pair<int, GameItem*> GameItemPair : *pGameItemsMap)
    {
        int tmpId = GameItemPair.first;
        vctItemIds.push_back(tmpId);
    }

    // ��itemIds�����������ѡ�����н���׼���ϼܵ���Ʒid
    vector<int> vctItemIdsRandom;
    for (int i = 0; i < nTodayNums; ++i)
    {
        int idx_min = 0;
        int idx_max = vctItemIds.size() - 1;
        int idx_tmp = RandomUtil::getRandomInteger(idx_min, idx_max);
        vctItemIdsRandom.push_back(vctItemIds[idx_tmp]); // ��ѡ�е�id���뵽������
        vctItemIds.erase(vctItemIds.begin() + idx_tmp);   // Ĩ���Ѿ���ѡ�е�id
    }

    sort(vctItemIdsRandom.begin(), vctItemIdsRandom.end());
    
    // 2.�����Ѿ���ѡ�õ���Ʒid������ɼ۸� ���洢��BlackMarket������
    vector<GameItem*>* vctMarketItemList = market->getItemList();
    vctMarketItemList->clear();
    for (int nitemId : vctItemIdsRandom)
    {
        GameItem* pItem = pGameItemsMap->at(nitemId);
        GameItem* pCommodity = new GameItem();
        int commodity_price = RandomUtil::getRandomInteger(pItem->GetMinPrice(), pItem->GetMaxPrice());
        pCommodity->SetId(pItem->GetId());
        pCommodity->SetName(pItem->GetName());
        pCommodity->SetOutPrice(commodity_price);
        pCommodity->SetCount(100);
        vctMarketItemList->push_back(pCommodity);
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
    gameMenuView->EnterGameMainView();
}




