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
 * �������ģʽ(����ģʽ)��
 * 1.������ֻ����һ��ʵ��
 * 2.����������Լ�����Ψһʵ��
 * 3.�����������������������ṩ���һ��ʵ��
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
    int                     m_curTime;      // ��Ϸ��ǰʱ��
    int                     m_maxTime;      // ��Ϸ���ʱ��
    GameRole*               m_pRole;        // ��Ϸ��ɫ
    vector<GameScene*>      m_gameScenes;   // ��������
    vector<RailStation*>    m_railStations; // ����վ����
    map<int, GameItem*>     m_gameItems;    // ��Ʒ����

    static GameModel*   s_instance;
};

