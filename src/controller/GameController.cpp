#include "GameController.h"
///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************



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
}

void GameController::finish()
{
}


