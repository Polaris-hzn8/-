///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <vector>
#include "GameRole.h"
#include "GameScene.h"

class GameModel {
public:
    GameModel();
    virtual ~GameModel();
    static GameModel* getInstance();

    int getCurTime() { return m_curTime; }
    void setCurTime(int time) { m_curTime = time; }
    int getMaxTime() { return m_maxTime; }
    void setMaxTime(int time) { m_maxTime = time; }

    GameRole* getRole();
    vector<GameScene*>* getGameScenes() { return &m_gameScenes; };

protected:
private:
    int m_curTime;                      // ��Ϸ��ǰʱ��
    int m_maxTime;                      // ��Ϸ���ʱ��
    GameRole* m_pRole;                  // ��Ϸ��ɫ
    vector<GameScene*> m_gameScenes;    // ��Ϸ��������
    static GameModel* s_instance;
};

