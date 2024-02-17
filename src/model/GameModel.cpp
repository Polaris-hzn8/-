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
    string names[] = {"地铁站", "银行", "邮局", "医院", "机场", "租房中介", "网吧"};
    for (int i = 0; i < sizeof(names)/sizeof(*names); ++i) {
        GameScene* gameScene = new GameScene();
        gameScene->SetId(i + 1);
        gameScene->setSceneName(names[i]);
        m_gameScenes.push_back(gameScene);
    }
}

GameModel::~GameModel()
{
    if (m_pRole) {
        delete m_pRole;
        m_pRole = nullptr;
    }
    if (m_gameScenes.empty()) {
        for (GameScene* gameScene : m_gameScenes) {
            delete gameScene;
            gameScene = nullptr;
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



