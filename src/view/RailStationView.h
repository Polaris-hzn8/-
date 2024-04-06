///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-03-26 22:57
/// @Mail		: 3453851623@qq.com
/// @Brief		: 游戏地铁站界面视图类
///****************************************************************************

#pragma once

#include "GameInfoView.h"
#include "Model/BlackMarket.h"

class RailStationView : public GameInfoView
{
public:
	RailStationView();
	~RailStationView();

	void show() override;
private:
	void showStationNet();
};

