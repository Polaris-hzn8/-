///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <iostream>
#include "View/GameMenuView.h"
#include "Model/GameModel.h"
#include "Model/BlackMarket.h"
#include "Controller/GameCore.h"
using namespace std;

class GameCore
{
public:
    GameCore();
    virtual ~GameCore();
    static GameCore* getInstance();

    void start();       // 游戏开始
    void finish();      // 游戏结束

private:
    void logicUpdate();                         // 逻辑刷新
    void MarketListUpdate(BlackMarket *market); // 黑市商品数据更新
    void screenUpdate();                        // 显示刷新

    bool m_bGameRuning;     // 游戏主循环运行状态
    static GameCore* s_instance;
};


