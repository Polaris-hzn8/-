///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "GameView.h"
#include "RailStationView.h"
#include "Model/GameModel.h"

RailStationView::RailStationView()
{
}

RailStationView::~RailStationView()
{
}

void RailStationView::show()
{
	// 实现游戏基本信息
	GameInfoView::show();
	// 显示地铁站网络图
	// 获取所有地铁站名称
	vector<string> stationNames;
	vector<RailStation*>* railStations = GameModel::getInstance()->getRailStations();
	for (RailStation* railStation : *railStations)
	{
		string stationName = railStation->GetName();
		stationNames.push_back(stationName);
	}
	// 显示地铁站网络图
	string menuName = "城市地面示意图->地铁站";
	int nId = chooseItemInMenu(menuName, stationNames) - 1;

	// 显示黑市基本信息
	RailStation* railStation = railStations->at(nId);				// 根据id获取地铁站对象
	BlackMarket* market = railStation->getMarket();					// 根据地铁站对象获取黑市对象
	showStationMarket(market);										// 显示每个地铁站独有的黑市界面
}

void RailStationView::showStationMarket(BlackMarket* market)
{
	// 实现游戏基本信息
	GameInfoView::show();
	// 黑市商品列表显示
	cout << "您当前正在" << market->GetName() << "的黑市交易所,今日黑市商品如下:" << endl;
	vector<GameItem*>* pItemList = market->getItemList();
	for (int i = 1; i <= pItemList->size(); ++i)
	{
		GameItem* gameItem = (*pItemList)[i - 1];
		string itemName = gameItem->GetName();			// 商品名称
		int outPrice = gameItem->GetOutPrice();			// 商品出售价格
		int count = gameItem->GetCount();				// 商品剩余数量

		char space = ' ';
		string strPrice = to_string(outPrice);
		string space_n1(15 - itemName.length(), ' ');
		string space_n2(6 - strPrice.length(), ' ');

		char buff[1024];
		sprintf_s(buff, "%d.%s%sPrice:%d%s$ Remains:%d", i, itemName.c_str(), space_n1.c_str(), outPrice, space_n2.c_str(), count);
		cout << buff << endl;
	}

	cout << string(80, '*') << endl;

	// 出租屋货物列表显示
	GameRole* playerInfo = GameModel::getInstance()->getRole();
	vector<GameItem*>* playerGoods = playerInfo->getGoods();
	int nCurStoreUse = playerInfo->GetCurStoreUse();
	int nMaxStoreCapa = playerInfo->GetMaxStoreCapa();
	char buff[1024];
	sprintf_s(buff, "出租屋货物列表如下(%d/%d):", nCurStoreUse, nMaxStoreCapa);
	cout << buff << endl;
	if (nCurStoreUse == 0)
	{
		cout << "空无一物" << endl;
	}
	else
	{
		for (int i = 1; i <= playerGoods->size(); ++i)
		{
			GameItem* gameItem = (*playerGoods)[i - 1];
			string itemName = gameItem->GetName();			// 商品名称
			int outPrice = gameItem->GetOutPrice();			// 商品出售价格
			int count = gameItem->GetCount();				// 商品剩余数量

			char space = ' ';
			string strPrice = to_string(outPrice);
			string space_n1(15 - itemName.length(), ' ');
			string space_n2(6 - strPrice.length(), ' ');

			char buff[1024];
			sprintf_s(buff, "%d.%s%sPrice:%d%s$ Remains:%d", i, itemName.c_str(), space_n1.c_str(), outPrice, space_n2.c_str(), count);
			cout << buff << endl;
		}
	}
	
	cout << string(80, '*') << endl;

	// 等待玩家进行购买与出售操作
	string choice;
	cin >> choice;

}

