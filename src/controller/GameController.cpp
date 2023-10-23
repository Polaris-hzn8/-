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
    // �������ֲ���
    SoundController::getInstance()->playBGM();

    // �������鶯���Ĳ���
    Viewer::getInstance()->showEntryAnimation();

    // ϵͳ�˵���չʾ
    Viewer::getInstance()->showMenu();


}

void GameController::finish()
{
}


