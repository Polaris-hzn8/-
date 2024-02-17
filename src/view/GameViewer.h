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

    // �˵����
    void showEntryAnimation();
    void showMenu();
    // ��װ�˵�ѡ���б�
    int chooseItemInMenu(string menuName, vector<string> itemNames);

    // ��Ϸ���
    void startGameDisplay();
    void finishGameDisplay();
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
private:
    GameMainView* m_pGameMainView;
    static GameViewer* s_instance;
};

