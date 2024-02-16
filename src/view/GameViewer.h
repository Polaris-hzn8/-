///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <windows.h>
#include "Controller/GameCore.h"
#include "Controller/SoundController.h"
using namespace std;

class GameViewer {
public:
    GameViewer();
    virtual ~GameViewer();
    static GameViewer* getInstance();

    void showEntryAnimation();
    void showMenu();

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

    static GameViewer* s_instance;
};

