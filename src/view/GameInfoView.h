///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-03-26 22:57
/// @Mail		: 3453851623@qq.com
/// @Brief		: 
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
	// 封装菜单选择列表
	int chooseItemInMenu(string menuName, vector<string> itemNames);
protected:
	virtual void show();
private:
	void showTime();		// 展示游戏时间
	void showEvent();		// 展示随机事件
	void showRoleInfo();	// 展示玩家角色属性
	int m_curTime;
	int m_maxTime;
	GameRole* m_pRole;
};
