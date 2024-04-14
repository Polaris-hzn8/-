///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <iostream>
#include <sstream>
#include <windows.h>
#include <mmsystem.h>
#include <vector>
using namespace std;

/**
 * 单例设计模式(饿汉模式)：
 * 1.单例类只能有一个实例
 * 2.单例类必须自己创建唯一实例
 * 3.单例类必须给所有其他对象提供这个一个实例
 */

class SoundController {
public:
    SoundController(const SoundController& soundController) = delete;                 // 禁用拷贝构造函数
    SoundController& operator=(const SoundController& soundController) = delete;      // 禁用拷贝赋值操作重载函数
    static SoundController* getInstance();
    virtual ~SoundController();

    void playSound(int id); // 音效播放
    void stopSound(int id); // 音效停止
    void playBGM();         // 背景音乐播放
    void stopBGM();         // 背景音乐停止
    void stopAll();         // 停止所有的声音

    // 获取当前系统是否静音
    bool getSlience();
    bool setSlience(bool silence);

protected:
private:
    bool m_slience;

    SoundController();
    static SoundController* s_instance;
};
