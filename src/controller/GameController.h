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
    GameController(const GameController& gameController) = delete;                 // 禁用拷贝构造函数
    GameController& operator=(const GameController& gameController) = delete;      // 禁用拷贝赋值操作重载函数
    static GameController* getInstance();
    virtual ~GameController();

    void start();   //应用开始
    void finish();  //应用结束

protected:
private:
    GameController();
    static GameController* s_instance;
};
