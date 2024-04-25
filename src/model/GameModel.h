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
#include "EventMessage.h"

/**
 * 单例设计模式(饿汉模式)：
 * 1.单例类只能有一个实例
 * 2.单例类必须自己创建唯一实例
 * 3.单例类必须给所有其他对象提供这个一个实例
 */

class GameModel {
public:
    GameModel(const GameModel& gameModel) = delete;                 // 禁用拷贝构造函数
    GameModel& operator=(const GameModel& gameModel) = delete;      // 禁用拷贝赋值操作重载函数
    static GameModel* getInstance();
    virtual ~GameModel();

    void initData();    // 初始化所有数据

    int getCurTime() { return m_curTime; }
    void setCurTime(int time) { m_curTime = time; }
    int getMaxTime() { return m_maxTime; }
    void setMaxTime(int time) { m_maxTime = time; }

    // 获取角色信息
    GameRole* getRole();
    // 获取游戏场景信息
    vector<GameScene*>* getGameScenes() { return &m_gameScenes; }
    // 获取地铁站信息
    vector<RailStation*>* getRailStations() { return &m_railStations; }
    // 获取游戏商品信息
    map<int, GameItem*>* getGameItems() { return &m_gameItems; }
    // 获取小道消息记录
    map<int, EventMessage*>* getGameMessages() { return &m_mapGameMessages; }

protected:
private:
    int                     m_curTime;          // 游戏当前时间
    int                     m_maxTime;          // 游戏最大时间
    GameRole*               m_pRole;            // 游戏角色
    vector<GameScene*>      m_gameScenes;       // 场景集合
    vector<RailStation*>    m_railStations;     // 地铁站集合
    map<int, GameItem*>     m_gameItems;        // 商品集合
    map<int, EventMessage*> m_mapGameMessages;  // 消息记录

    GameModel();                            // 构造函数私有化
    static GameModel* s_instance;
};

