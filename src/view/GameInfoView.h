///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include "model/GameModel.h"
#include "Model/GameRole.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GameInfoView
{
public:
	GameInfoView();
	~GameInfoView();
protected:
	virtual void showGameInfo();
private:
	void init();
	void showTime();		// 展示游戏时间
	void showEvent();		// 展示随机事件
	void showRoleInfo();	// 展示玩家角色属性
	int m_curTime;
	int m_maxTime;
	GameRole* m_pRole;
};
