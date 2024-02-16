///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <iostream>
#include "View/GameViewer.h"
#include "Model/GameModel.h"
#include "Controller/GameCore.h"
using namespace std;

class GameCore
{
public:
    GameCore();
    virtual ~GameCore();
    static GameCore* getInstance();

    void startGame();
    void gameOver();

private:
    void logicUpdate();     // �߼�ˢ��
    void screenUpdate();    // ��ʾˢ��

    bool m_gameState;       // ��Ϸ��ѭ������״̬
    static GameCore* s_instance;
};


