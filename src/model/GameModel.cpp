///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "GameModel.h"

GameModel* GameModel::s_instance = nullptr;

GameModel* GameModel::getInstance()
{
    if (s_instance == nullptr) {
        s_instance = new GameModel;
    }
    return s_instance;
}

GameModel::GameModel()
{
    m_curTime = 0;
    m_maxTime = 40;
}

GameModel::~GameModel()
{

}

int GameModel::getCurTime()
{
    return m_curTime;
}

void GameModel::setCurTime(int time)
{
    m_curTime = time;
}

int GameModel::getMaxTime()
{
    return m_maxTime;
}


