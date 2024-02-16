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
    int m_curTime; // ��Ϸ��ǰʱ��
    int m_maxTime; // ��Ϸ���ʱ��
    static GameModel* s_instance;
};

