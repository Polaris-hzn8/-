///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-03-26 22:57
/// @Mail		: 3453851623@qq.com
///****************************************************************************

#include <algorithm>
#include "GameCore.h"
#include "Model/GameModel.h"
#include "View/GameMenuView.h"
#include "utility/RandomUtil.h"
#include "Controller/GameCore.h"
#include "controller/EventController.h"

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
    // ������Ϸ����
    EventController::getInstance()->LoadingData();
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
 * ˢ����Ϸ����logicUpdate
 * 1.�ж���Ϸ�Ƿ����
 * 2.�µ�1�촥����Ϸ�¼�
 * 3.ˢ����Ϸ����
 * (1) ˢ�µ�ǰ��Ϸʱ��
 * (2) ˢ����Ҵ����Ƿծ����
 * (3) ˢ��ÿ�պ�����Ʒ����
 */
void GameCore::logicUpdate()
{
    GameModel* gameModel = GameModel::getInstance();

    // �ж���Ϸ�Ƿ����
    int curTime = gameModel->getCurTime();
    int maxTime = gameModel->getMaxTime();
    if (curTime > maxTime)
        finish();

    // �µ�1�촥����Ϸ�¼�
    // ���ý����¼�
    gameModel->setCurEventMessage(nullptr);
    // ���ɽ����¼�
    if (RandomUtil::getProbabilityResult(50))
    {
        int id = RandomUtil::getRandomInteger(0, gameModel->getGameMessages()->size());
        EventController::getInstance()->WallMessage(id);
    }

    // ˢ�µ�ǰ��Ϸʱ��
    gameModel->setCurTime(curTime + 1);

    // ˢ����Ҵ����Ƿծ����
    GameRole* pRole = gameModel->getRole();

    // ���
    int deposit = (int)pRole->GetDeposit() * 1.05f;
    pRole->SetDeposit(deposit);

    // Ƿծ
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
    GameModel* pGameModel = GameModel::getInstance();
    map<int, GameItem*>* pGameItemsMap = pGameModel->getGameItems();
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
    for (int nItemId : vctItemIdsRandom)
    {
        GameItem* pItem = pGameItemsMap->at(nItemId);
        GameItem* pCommodity = new GameItem();
        int commodity_price = RandomUtil::getRandomInteger(pItem->GetMinPrice(), pItem->GetMaxPrice());

        // ���������¼�������� ָ����Ʒ�۸����Ӱ��
        EventMessage* pCurEventMessage = pGameModel->getCurEventMessage();
        if (pCurEventMessage &&
            pCurEventMessage->GetGoodsId() == nItemId)
        {
            if (pCurEventMessage->GetPriceInc() > 0)
            {
                // �۸񷭱�
                commodity_price = commodity_price * pCurEventMessage->GetPriceInc();
            }
            else if(pCurEventMessage->GetPriceDec() > 0)
            {
                // �۸����
                commodity_price = commodity_price * pCurEventMessage->GetPriceInc();
            }
        }

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




