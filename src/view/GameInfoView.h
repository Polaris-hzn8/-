///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <iostream>
using namespace std;

class GameInfoView
{
public:
	GameInfoView();
	~GameInfoView();
protected:
	virtual void showGameInfo();
private:
	void showTime(int curTime, int maxTime);// 展示游戏时间
	void showEvent();						// 展示随机事件
	void showRoleInfo();					// 展示玩家角色属性
	int m_pcurTime;
	int m_pmaxTime;
};
