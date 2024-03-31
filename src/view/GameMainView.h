///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
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

