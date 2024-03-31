///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
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
	void showStationMarket(BlackMarket *market);	// 显示地铁站不同界面（黑市界面）
};

