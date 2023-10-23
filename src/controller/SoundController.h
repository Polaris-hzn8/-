///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <iostream>
#include <sstream>
#include <windows.h>
#include <mmsystem.h>
using namespace std;

class SoundController {
public:
    SoundController();
    virtual ~SoundController();
    static SoundController* getInstance();

public:
    // ������Ч
    void playSound(int id);
    // ֹͣ������Ч
    void stopSound(int id);
    // ���ű�������
    void playBGM();
    // ֹͣ���ű�������

    // ֹͣ���е���������

protected:
private:
    static SoundController* s_instance;
};
