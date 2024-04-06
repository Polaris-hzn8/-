///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "RailStationView.h"
#include "Model/GameModel.h"
#include "BlackMarketView.h"

RailStationView::RailStationView()
{
}

RailStationView::~RailStationView()
{
}

void RailStationView::show()
{
	// 显示游戏基本信息
	GameInfoView::show();
	// 显示地铁站网络
	showStationNet();
}

void RailStationView::showStationNet()
{
	// 获取所有地铁站名称 并显示地铁站网络图
	vector<string> stationNames;
	vector<RailStation*>* railStations = GameModel::getInstance()->getRailStations();
	for (RailStation* railStation : *railStations)
	{
		string stationName = railStation->GetName();
		stationNames.push_back(stationName);
	}
	string menuName = "城市地面示意图->地铁站";
	int nId = chooseItemInMenu(menuName, stationNames) - 1;

	// 在玩家选择地铁站后 显示具体的黑市信息
	RailStation* pRailStation = railStations->at(nId);							// 根据id获取地铁站对象
	BlackMarket* pBlackMarket = pRailStation->getMarket();						// 根据地铁站对象获取黑市对象
	BlackMarketView* pBlackMarketView = BlackMarketView::create(pBlackMarket);	// 根据黑市对象创建黑市视图对象
	pBlackMarketView->show();
}

