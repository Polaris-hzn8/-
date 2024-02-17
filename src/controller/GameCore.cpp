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

// ��Ϸ��ѭ��
void GameCore::start()
{
    m_gameState = true;
    while (m_gameState) {
        logicUpdate();  // �߼�ˢ��
        screenUpdate(); // ��ʾˢ��
    }
}

void GameCore::finish()
{
    m_gameState = false;
}

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



