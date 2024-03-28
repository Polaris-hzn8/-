///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include "GameInfoView.h"

class RailStationView : public GameInfoView
{
public:
	RailStationView();
	~RailStationView();

	void showGameInfo() override;
private:
	void showStationNet();
};

