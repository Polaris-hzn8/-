///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include "View/GameMenuView.h"
#include "Controller/SoundController.h"

/**
 * 单例设计模式(饿汉模式)：
 * 1.单例类只能有一个实例
 * 2.单例类必须自己创建唯一实例
 * 3.单例类必须给所有其他对象提供这个一个实例
 */

class GameController {
public:
    GameController();
    virtual ~GameController();
    static GameController* getInstance();

    void start();   //应用开始
    void finish();  //应用结束

protected:
private:
    static GameController* s_instance;
};
