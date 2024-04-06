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

/**
 * 单例设计模式(饿汉模式)：
 * 1.单例类只能有一个实例
 * 2.单例类必须自己创建唯一实例
 * 3.单例类必须给所有其他对象提供这个一个实例
 */

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


