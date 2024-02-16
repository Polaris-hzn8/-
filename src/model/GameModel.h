///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

class GameModel {
public:
    GameModel();
    virtual ~GameModel();
    static GameModel* getInstance();

    int getCurTime();
    void setCurTime(int time);
    int getMaxTime();

protected:
private:
    int m_curTime; // 游戏当前时间
    int m_maxTime; // 游戏最大时间
    static GameModel* s_instance;
};

