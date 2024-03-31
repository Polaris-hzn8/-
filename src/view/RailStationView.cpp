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
	// ʵ����Ϸ������Ϣ
	GameInfoView::show();
	// ��ʾ����վ����ͼ
	// ��ȡ���е���վ����
	vector<string> stationNames;
	vector<RailStation*>* railStations = GameModel::getInstance()->getRailStations();
	for (RailStation* railStation : *railStations)
	{
		string stationName = railStation->GetName();
		stationNames.push_back(stationName);
	}
	// ��ʾ����վ����ͼ
	string menuName = "���е���ʾ��ͼ->����վ";
	int nId = chooseItemInMenu(menuName, stationNames) - 1;

	// ��ʾ���л�����Ϣ
	RailStation* railStation = railStations->at(nId);				// ����id��ȡ����վ����
	BlackMarket* market = railStation->getMarket();					// ���ݵ���վ�����ȡ���ж���
	showStationMarket(market);										// ��ʾÿ������վ���еĺ��н���
}

void RailStationView::showStationMarket(BlackMarket* market)
{
	// ʵ����Ϸ������Ϣ
	GameInfoView::show();
	// ������Ʒ�б���ʾ
	cout << "����ǰ����" << market->GetName() << "�ĺ��н�����,���պ�����Ʒ����:" << endl;
	vector<GameItem*>* pItemList = market->getItemList();
	for (int i = 1; i <= pItemList->size(); ++i)
	{
		GameItem* gameItem = (*pItemList)[i - 1];
		string itemName = gameItem->GetName();			// ��Ʒ����
		int outPrice = gameItem->GetOutPrice();			// ��Ʒ���ۼ۸�
		int count = gameItem->GetCount();				// ��Ʒʣ������

		char space = ' ';
		string strPrice = to_string(outPrice);
		string space_n1(15 - itemName.length(), ' ');
		string space_n2(6 - strPrice.length(), ' ');

		char buff[1024];
		sprintf_s(buff, "%d.%s%sPrice:%d%s$ Remains:%d", i, itemName.c_str(), space_n1.c_str(), outPrice, space_n2.c_str(), count);
		cout << buff << endl;
	}

	cout << string(80, '*') << endl;

	// �����ݻ����б���ʾ
	GameRole* playerInfo = GameModel::getInstance()->getRole();
	vector<GameItem*>* playerGoods = playerInfo->getGoods();
	int nCurStoreUse = playerInfo->GetCurStoreUse();
	int nMaxStoreCapa = playerInfo->GetMaxStoreCapa();
	char buff[1024];
	sprintf_s(buff, "�����ݻ����б�����(%d/%d):", nCurStoreUse, nMaxStoreCapa);
	cout << buff << endl;
	if (nCurStoreUse == 0)
	{
		cout << "����һ��" << endl;
	}
	else
	{
		for (int i = 1; i <= playerGoods->size(); ++i)
		{
			GameItem* gameItem = (*playerGoods)[i - 1];
			string itemName = gameItem->GetName();			// ��Ʒ����
			int outPrice = gameItem->GetOutPrice();			// ��Ʒ���ۼ۸�
			int count = gameItem->GetCount();				// ��Ʒʣ������

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

	// �ȴ���ҽ��й�������۲���
	string choice;
	cin >> choice;

}

