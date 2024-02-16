///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "GameController.h"

GameController* GameController::s_instance = nullptr;

GameController* GameController::getInstance()
{
    if (!s_instance) {
        s_instance = new GameController();
    }
    return s_instance;
}

GameController::GameController()
{
}

GameController::~GameController()
{
}

void GameController::start()
{
    // 背景音乐播放
    //SoundController::getInstance()->playBGM();
    // 开场剧情动画的播放
    //GameViewer::getInstance()->showEntryAnimation();
    // 系统菜单的展示
    GameViewer::getInstance()->showMenu();

}

void GameController::finish()
{
}


