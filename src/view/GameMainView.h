///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-04-04 10:39
/// @Mail		: 3453851623@qq.com
/// @brief		: 游戏主界面视图类
///****************************************************************************

#pragma once

#include "GameInfoView.h"
#include "Model/GameScene.h"

class GameMainView:public GameInfoView
{
public:
	GameMainView();
	~GameMainView();
	
	void show() override;
	int chooseItemInMenu(string menuName, vector<string> itemNames);

private:
	void showChoice();
};

