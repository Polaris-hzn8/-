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
    // ≤•∑≈“Ù–ß
    void playSound(int id);
    // Õ£÷π≤•∑≈“Ù–ß
    void stopSound(int id);
    // ≤•∑≈±≥æ∞“Ù¿÷
    void playBGM();
    // Õ£÷π≤•∑≈±≥æ∞“Ù¿÷

    // Õ£÷πÀ˘”–µƒ…˘“Ù≤•∑≈

protected:
private:
    static SoundController* s_instance;
};
