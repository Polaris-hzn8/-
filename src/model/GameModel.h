///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <map>
#include <vector>
#include "GameItem.h"
#include "GameRole.h"
#include "GameScene.h"
#include "RailStation.h"

/**
 * 单例设计模式(饿汉模式)：
 * 1.单例类只能有一个实例
 * 2.单例类必须自己创建唯一实例
 * 3.单例类必须给所有其他对象提供这个一个实例
 */

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
    vector<GameScene*>* getGameScenes() { return &m_gameScenes; }
    vector<RailStation*>* getRailStations() { return &m_railStations; }
    map<int, GameItem*>* getGameItems() { return &m_gameItems; }

protected:
private:
    int                     m_curTime;      // 游戏当前时间
    int                     m_maxTime;      // 游戏最大时间
    GameRole*               m_pRole;        // 游戏角色
    vector<GameScene*>      m_gameScenes;   // 场景集合
    vector<RailStation*>    m_railStations; // 地铁站集合
    map<int, GameItem*>     m_gameItems;    // 商品集合

    static GameModel*   s_instance;
};

