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
    // �˵���1
    void showGameMenu();
    void showGameRank();
    void showGameSetting();
    // �˵���2
    void showSceneMenu();

    // �˵���3
    void showHelpMenu();

    // ��װ�˵�ѡ���б�
    int chooseItemInMenu(string menuName, vector<string> itemNames);

    static GameViewer* s_instance;
};

