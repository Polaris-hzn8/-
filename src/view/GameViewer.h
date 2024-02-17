///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <windows.h>
#include "GameInfoView.h"
#include "GameMainView.h"
#include "Controller/GameCore.h"
#include "Controller/SoundController.h"
using namespace std;

class GameViewer {
public:
    GameViewer();
    virtual ~GameViewer();
    static GameViewer* getInstance();

    // 菜单相关
    void showEntryAnimation();
    void showMenu();
    // 封装菜单选择列表
    int chooseItemInMenu(string menuName, vector<string> itemNames);

    // 游戏相关
    void startGameDisplay();
    void finishGameDisplay();
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
private:
    GameMainView* m_pGameMainView;
    static GameViewer* s_instance;
};

