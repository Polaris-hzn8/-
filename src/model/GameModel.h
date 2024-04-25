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
 * �������ģʽ(����ģʽ)��
 * 1.������ֻ����һ��ʵ��
 * 2.����������Լ�����Ψһʵ��
 * 3.�����������������������ṩ���һ��ʵ��
 */

class GameModel {
public:
    GameModel(const GameModel& gameModel) = delete;                 // ���ÿ������캯��
    GameModel& operator=(const GameModel& gameModel) = delete;      // ���ÿ�����ֵ�������غ���
    static GameModel* getInstance();
    virtual ~GameModel();

    void initData();    // ��ʼ����������

    int getCurTime() { return m_curTime; }
    void setCurTime(int time) { m_curTime = time; }
    int getMaxTime() { return m_maxTime; }
    void setMaxTime(int time) { m_maxTime = time; }

    // ��ȡ��ɫ��Ϣ
    GameRole* getRole();
    // ��ȡ��Ϸ������Ϣ
    vector<GameScene*>* getGameScenes() { return &m_gameScenes; }
    // ��ȡ����վ��Ϣ
    vector<RailStation*>* getRailStations() { return &m_railStations; }
    // ��ȡ��Ϸ��Ʒ��Ϣ
    map<int, GameItem*>* getGameItems() { return &m_gameItems; }
    // ��ȡС����Ϣ��¼
    map<int, EventMessage*>* getGameMessages() { return &m_mapGameMessages; }

protected:
private:
    int                     m_curTime;          // ��Ϸ��ǰʱ��
    int                     m_maxTime;          // ��Ϸ���ʱ��
    GameRole*               m_pRole;            // ��Ϸ��ɫ
    vector<GameScene*>      m_gameScenes;       // ��������
    vector<RailStation*>    m_railStations;     // ����վ����
    map<int, GameItem*>     m_gameItems;        // ��Ʒ����
    map<int, EventMessage*> m_mapGameMessages;  // ��Ϣ��¼

    GameModel();                            // ���캯��˽�л�
    static GameModel* s_instance;
};

