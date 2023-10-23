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
    m_curTime = 0;
    m_maxTime = 40;
}

GameWorld::~GameWorld()
{

}

int GameWorld::getCurTime()
{
    return m_curTime;
}

void GameWorld::setCurTime(int time)
{
    m_curTime = time;
}

int GameWorld::getMaxTime()
{
    return m_maxTime;
}


