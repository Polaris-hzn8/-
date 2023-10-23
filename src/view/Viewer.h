///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include "Controller/SoundController.h"
#include "Controller/GameCore.h"
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
    void showMenu();
    void showTime(int curTime, int maxTime);

protected:
private:
    void playTypeWrite(std::string line);
    // 菜单组1
    void showGameMenu();
    void showGameRank();
    void showGameSetting();
    // 菜单组2
    void showSceneMenu();

    // 菜单组3
    void showHelpMenu();

    // 封装菜单选择列表
    int chooseItemInMenu(string menuName, vector<string> itemNames);

private:
    static Viewer* s_instance;
};

