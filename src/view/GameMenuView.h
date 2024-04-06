///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-04-04 10:39
/// @Mail		: 3453851623@qq.com
/// @brief		: 菜单界面视图类
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
 * 单例设计模式(饿汉模式)：
 * 1.单例类只能有一个实例
 * 2.单例类必须自己创建唯一实例
 * 3.单例类必须给所有其他对象提供这个一个实例
 */

class GameMenuView {
public:
    GameMenuView();
    virtual ~GameMenuView();
    static GameMenuView* getInstance();

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
    static GameMenuView* s_instance;
};

