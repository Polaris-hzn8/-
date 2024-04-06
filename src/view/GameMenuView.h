///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-04-04 10:39
/// @Mail		: 3453851623@qq.com
/// @brief		: �˵�������ͼ��
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

/**
 * �������ģʽ(����ģʽ)��
 * 1.������ֻ����һ��ʵ��
 * 2.����������Լ�����Ψһʵ��
 * 3.�����������������������ṩ���һ��ʵ��
 */

class GameMenuView {
public:
    GameMenuView();
    virtual ~GameMenuView();
    static GameMenuView* getInstance();

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
    static GameMenuView* s_instance;
};

