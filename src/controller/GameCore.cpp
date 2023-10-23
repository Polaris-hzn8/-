///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "GameCore.h"

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
    m_gameState = false;
}

GameCore::~GameCore()
{

}

void GameCore::startGame()
{
    m_gameState = true;
    // 游戏主循环
    while (m_gameState) {
        // 逻辑刷新
        void logicUpdate();
        // 显示刷新
        void screenUpdate();
    }
}

void GameCore::gameOver()
{
    m_gameState = false;
}

void GameCore::logicUpdate()
{
    GameWorld *gameWorld = GameWorld::getInstance();
    if (gameWorld->getCurTime() <= gameWorld->getMaxTime()) {
        gameWorld->setCurTime(gameWorld->getCurTime() + 1);
    } else {
        gameOver();
    }
}

void GameCore::screenUpdate()
{
    GameWorld* gameWorld = GameWorld::getInstance();
    Viewer* viewer = Viewer::getInstance();
    if (gameWorld->getCurTime() > gameWorld->getMaxTime()) {
        return;
    }
    viewer->showTime(gameWorld->getCurTime(), gameWorld->getMaxTime());
}



