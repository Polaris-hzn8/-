///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-03-26 22:57
/// @Mail		: 3453851623@qq.com
/// @Brief		: ��Ϸ����վ������ͼ��
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

