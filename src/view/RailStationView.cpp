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
	// ��ʾ��Ϸ������Ϣ
	GameInfoView::show();
	// ��ʾ����վ����
	showStationNet();
}

void RailStationView::showStationNet()
{
	// ��ȡ���е���վ���� ����ʾ����վ����ͼ
	vector<string> stationNames;
	vector<RailStation*>* railStations = GameModel::getInstance()->getRailStations();
	for (RailStation* railStation : *railStations)
	{
		string stationName = railStation->GetName();
		stationNames.push_back(stationName);
	}
	string menuName = "���е���ʾ��ͼ->����վ";
	int nId = chooseItemInMenu(menuName, stationNames) - 1;

	// �����ѡ�����վ�� ��ʾ����ĺ�����Ϣ
	RailStation* pRailStation = railStations->at(nId);							// ����id��ȡ����վ����
	BlackMarket* pBlackMarket = pRailStation->getMarket();						// ���ݵ���վ�����ȡ���ж���
	BlackMarketView* pBlackMarketView = BlackMarketView::create(pBlackMarket);	// ���ݺ��ж��󴴽�������ͼ����
	pBlackMarketView->show();
}

