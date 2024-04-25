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
    // 初始化游戏场景 m_gameScenes
    string names[] = { "地铁站", "银行", "邮局", "医院", "机场", "租房中介", "网吧" };
    for (int i = 0; i < sizeof(names) / sizeof(*names); ++i)
    {
        GameScene* gameScene = new GameScene();
        gameScene->SetId(i);
        gameScene->setName(names[i]);
        m_gameScenes.push_back(gameScene);
    }

    // 初始化地铁站信息 m_railStations
    string stationNames[] =
    {
        "彭埠站",
        "七堡站",
        "九和路站",
        "九堡站",
        "客运中心站",
        "下沙西站",
        "金沙湖站",
        "高沙路站",
        "文泽路站",
        "文海南路站"
    };
    for (int i = 0; i < sizeof(stationNames) / sizeof(*stationNames); ++i)
    {
        RailStation* railStation = new RailStation();
        railStation->SetId(i);
        railStation->setName(stationNames[i]);
        m_railStations.push_back(railStation);
    }

    // 初始化黑市商品信息 m_gameItems
    // 商品名称
    string itemNames[] =
    {
        "进口香烟",
        "走私汽车",
        "盗版游戏",
        "勾兑白酒",
        "进口玩具",
        "山寨手机",
        "伪劣化妆品",
        "都市小宝贝"
    };
    // 商品价格范围
    const int itemNums = sizeof(itemNames) / sizeof(*itemNames);
    int itemPrice[itemNums][2] =
    {
        {100, 450},         //进口香烟
        {15000, 30000},     //走私汽车
        {5, 55},            //盗版游戏
        {1000, 3500},       //勾兑白酒
        {5000, 9000},       //进口玩具
        {250, 850},         //山寨手机
        {100, 450},         //伪劣化妆品
        {750, 1500}         //都市小宝贝
    };
    // 商品信息初始化
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



