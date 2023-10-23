///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <iostream>
#include "View/Viewer.h"
#include "Model/GameWorld.h"
#include "Controller/GameCore.h"
using namespace std;

class GameCore {
public:
    GameCore();
    virtual ~GameCore();
    static GameCore* getInstance();

public:
    void startGame();
    void gameOver();

private:
    void logicUpdate();     // 逻辑刷新
    void screenUpdate();    // 显示刷新

private:
    static GameCore* s_instance;
    bool m_gameState;               // 游戏主循环运行状态
};


