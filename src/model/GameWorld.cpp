///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "GameWorld.h"

GameWorld* GameWorld::s_instance = nullptr;

GameWorld* GameWorld::getInstance()
{
    if (s_instance == nullptr) {
        s_instance = new GameWorld;
    }
    return s_instance;
}

GameWorld::GameWorld()
{
}

GameWorld::~GameWorld()
{
}
