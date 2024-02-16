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

// 游戏主循环
void GameCore::startGame()
{
    m_gameState = true;
    while (m_gameState) {
        logicUpdate();  // 逻辑刷新
        screenUpdate(); // 显示刷新
        Sleep(1 * 1000);
    }
}

void GameCore::gameOver()
{
    m_gameState = false;
}

void GameCore::logicUpdate()
{
    GameModel *gameModel = GameModel::getInstance();
    // 游戏时间刷新
    int curTime = gameModel->getCurTime();
    int maxTime = gameModel->getMaxTime();
    if (curTime <= maxTime) {
        gameModel->setCurTime(curTime + 1);
    } else {
        gameOver();
    }
}

void GameCore::screenUpdate()
{
    GameModel *gameModel = GameModel::getInstance();
    GameViewer* gameViewer = GameViewer::getInstance();
    // 游戏时间显示
    int curTime = gameModel->getCurTime();
    int maxTime = gameModel->getMaxTime();
    if (curTime > maxTime) {
        return;
    }
    gameViewer->showTime(curTime, maxTime);


}



