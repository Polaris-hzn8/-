///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include "controller/SoundController.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Viewer {
public:
    Viewer();
    virtual ~Viewer();
    static Viewer* getInstance();

public:
    void showEntryAnimation();
    void showSystemMenu();

protected:
private:
    void playTypeWrite(std::string line);
    static Viewer* s_instance;
};

