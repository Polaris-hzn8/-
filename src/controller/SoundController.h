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
 * �������ģʽ(����ģʽ)��
 * 1.������ֻ����һ��ʵ��
 * 2.����������Լ�����Ψһʵ��
 * 3.�����������������������ṩ���һ��ʵ��
 */

class SoundController {
public:
    SoundController();
    virtual ~SoundController();
    static SoundController* getInstance();

    void playSound(int id); // ��Ч����
    void stopSound(int id); // ��Чֹͣ
    void playBGM();         // �������ֲ���
    void stopBGM();         // ��������ֹͣ
    void stopAll();         // ֹͣ���е�����

    // ��ȡ��ǰϵͳ�Ƿ���
    bool getSlience();
    bool setSlience(bool silence);

protected:
private:
    bool m_slience;
    static SoundController* s_instance;
};
