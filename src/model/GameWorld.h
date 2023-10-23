///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

class GameWorld {
public:
    GameWorld();
    virtual ~GameWorld();
    static GameWorld* getInstance();

public:
    int getCurTime();
    void setCurTime(int time);
    int getMaxTime();

protected:
private:
    static GameWorld* s_instance;
    int m_curTime; // ��Ϸ��ǰʱ��
    int m_maxTime; // ��Ϸ���ʱ��
};
