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
void GameCore::start()
{
    m_gameState = true;
    while (m_gameState) {
        logicUpdate();  // 逻辑刷新
        screenUpdate(); // 显示刷新
    }
}

void GameCore::finish()
{
    m_gameState = false;
}

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
}

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



