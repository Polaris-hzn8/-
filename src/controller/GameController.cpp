///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "GameController.h"
#include "View/Viewer.h"

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


    // 开场剧情动画的播放
    Viewer::getInstance()->playEntryAnimation();


    // 系统菜单的展示



}

void GameController::finish()
{
}


