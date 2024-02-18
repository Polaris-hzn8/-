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

// ��Ϸ��ѭ��
void GameCore::start()
{
    m_bGameRuning = true;
    while (m_bGameRuning) {
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
    if (curTime <= maxTime) {
        gameModel->setCurTime(curTime + 1);
    } else {
        finish();
    }

    // ˢ����Ҵ����Ƿծ����
    GameRole* pRole = gameModel->getRole();
    // ���´������
    int deposit = (int)pRole->GetDeposit() * 1.05f;
    pRole->SetDeposit(deposit);
    // ���Ƿծ����
    int debet = (int)pRole->GetDebt() * 1.1f;
    pRole->SetDebt(debet);

    // �������е���վ ��ˢ��ÿ������վ�еĺ�����Ʒ����
    vector<RailStation*>* railStations = gameModel->getRailStations();
    for (RailStation* railStation : *railStations) {
        // ��ȡ���ж���
        BlackMarket* market = railStation->getMarket();
        // ˢ�º�������
        MarketListUpdate(market);
    }


}

void GameCore::MarketListUpdate(BlackMarket* market)
{
    // ��ȡ��ʼ����Ʒ����
    map<int, GameItem*>* pGameItems = GameModel::getInstance()->getGameItems();

    // �����������Ʒ���� 5~7
    int itemNums = RandomUtil::getRandomInteger(5, 7);

    // �ӳ�ʼ��Ʒ������ѡ��itemNums�������� ��Ʒ��¼�������� ����֤�������ظ���Ʒ����
    // (1) �������randomItemIds
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
    
    // (2) ������Ʒʵ�� ������ɵ���Ʒ���� �洢��Market������
    vector<GameItem*>* itemList = market->getItemList();
    itemList->clear();
    for (int randomId : randomItemIds) {
        // ��GameModel�л�ȡpGameItems
        GameItem* item = pGameItems->at(randomId);
        // ������Ʒʵ�� ��GameModel�е�pGameItems��ͬ
        GameItem* commodity = new GameItem();
        // ���������Ʒ�Ľ��ռ۸�
        int randomPrice = RandomUtil::getRandomInteger(item->GetMinPrice(), item->GetMaxPrice());
        // ������Ʒ����
        commodity->SetId(item->GetId());
        commodity->SetName(item->GetName());
        commodity->SetOutPrice(randomPrice);
        itemList->push_back(commodity);
    }
}

/**
 * screenUpdateˢ����Ϸ��ʾ
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




