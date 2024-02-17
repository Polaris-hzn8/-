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
    int m_curTime;                      // 游戏当前时间
    int m_maxTime;                      // 游戏最大时间
    GameRole* m_pRole;                  // 游戏角色
    vector<GameScene*> m_gameScenes;    // 游戏场景集合
    static GameModel* s_instance;
};

