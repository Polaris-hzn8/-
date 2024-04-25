///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "GameModel.h"

GameModel* GameModel::s_instance = nullptr;

GameModel* GameModel::getInstance()
{
    if (s_instance == nullptr) {
        s_instance = new GameModel;
    }
    return s_instance;
}

GameModel::GameModel()
{
    m_curTime = 0;
    m_maxTime = 40;
    m_pRole = nullptr;
    m_pCurEventMessage = nullptr;

    initData();
}

void GameModel::initData()
{
    // ��ʼ����Ϸ���� m_gameScenes
    string names[] = { "����վ", "����", "�ʾ�", "ҽԺ", "����", "�ⷿ�н�", "����" };
    for (int i = 0; i < sizeof(names) / sizeof(*names); ++i)
    {
        GameScene* gameScene = new GameScene();
        gameScene->SetId(i);
        gameScene->setName(names[i]);
        m_gameScenes.push_back(gameScene);
    }

    // ��ʼ������վ��Ϣ m_railStations
    string stationNames[] =
    {
        "��վ",
        "�߱�վ",
        "�ź�·վ",
        "�ű�վ",
        "��������վ",
        "��ɳ��վ",
        "��ɳ��վ",
        "��ɳ·վ",
        "����·վ",
        "�ĺ���·վ"
    };
    for (int i = 0; i < sizeof(stationNames) / sizeof(*stationNames); ++i)
    {
        RailStation* railStation = new RailStation();
        railStation->SetId(i);
        railStation->setName(stationNames[i]);
        m_railStations.push_back(railStation);
    }

    // ��ʼ��������Ʒ��Ϣ m_gameItems
    // ��Ʒ����
    string itemNames[] =
    {
        "��������",
        "��˽����",
        "������Ϸ",
        "���Ұ׾�",
        "�������",
        "ɽկ�ֻ�",
        "α�ӻ�ױƷ",
        "����С����"
    };
    // ��Ʒ�۸�Χ
    const int itemNums = sizeof(itemNames) / sizeof(*itemNames);
    int itemPrice[itemNums][2] =
    {
        {100, 450},         //��������
        {15000, 30000},     //��˽����
        {5, 55},            //������Ϸ
        {1000, 3500},       //���Ұ׾�
        {5000, 9000},       //�������
        {250, 850},         //ɽկ�ֻ�
        {100, 450},         //α�ӻ�ױƷ
        {750, 1500}         //����С����
    };
    // ��Ʒ��Ϣ��ʼ��
    for (int i = 0; i < itemNums; ++i)
    {
        GameItem* gameItem = new GameItem();
        gameItem->SetId(i + 1000);
        gameItem->SetName(itemNames[i]);
        gameItem->SetMinPrice(itemPrice[i][0]);
        gameItem->SetMaxPrice(itemPrice[i][1]);
        pair<int, GameItem*> item_pair(gameItem->GetId(), gameItem);
        m_gameItems.insert(item_pair);
    }

}

GameModel::~GameModel()
{
    // m_pRole
    if (m_pRole)
    {
        delete m_pRole;
        m_pRole = nullptr;
    }
    // m_gameScenes
    if (!m_gameScenes.empty()) {
        for (GameScene* gameScene : m_gameScenes)
        {
            delete gameScene;
            gameScene = nullptr;
        }
    }
    // m_railStations
    if (!m_railStations.empty()) {
        for (RailStation* pRailStaion : m_railStations)
        {
            delete pRailStaion;
            pRailStaion = nullptr;
        }
    }
    // m_gameItems
    if (!m_gameItems.empty())
    {
        for (pair<int, GameItem*> gameItemPair : m_gameItems)
        {
            GameItem *pGameItme = gameItemPair.second;
            delete pGameItme;
            pGameItme = nullptr;
        }
    }
}

GameRole* GameModel::getRole()
{
    if (!m_pRole) {
        m_pRole = new GameRole();
    }
    return m_pRole;
}

string GameModel::GetItemNameById(int nItemId)
{
    string strItemName = "";
    GameItem* pGameItem = m_gameItems.at(nItemId);
    if (pGameItem)
    {
        strItemName = pGameItem->GetName();
    }
    return strItemName;
}



