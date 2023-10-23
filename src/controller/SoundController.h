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

class SoundController {
public:
    SoundController();
    virtual ~SoundController();
    static SoundController* getInstance();

public:
    // 播放音效
    void playSound(int id);
    // 停止播放音效
    void stopSound(int id);
    // 播放背景音乐
    void playBGM();
    // 停止播放背景音乐
    void stopBGM();
    // 停止所有的声音播放
    void stopAll();
    // 获取当前系统是否静音
    bool getSlience();
    bool setSlience(bool silence);

protected:
private:
    static SoundController* s_instance;
    bool m_slience;
};
