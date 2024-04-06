///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-03-26 22:57
/// @Mail		: 3453851623@qq.com
/// @Brief		: 
///****************************************************************************

#include "BlackMarketView.h"

BlackMarketView::BlackMarketView()
{
	m_pBlackMarket = nullptr;
}

BlackMarketView::~BlackMarketView()
{

}

// ����ģʽ
BlackMarketView* BlackMarketView::create(BlackMarket* pMarket)
{
	BlackMarketView* pBlackMarketView = new BlackMarketView();
	if (pBlackMarketView)
	{
		pBlackMarketView->m_pBlackMarket = pMarket;
	}
	else
	{
		delete pBlackMarketView;
		pBlackMarketView = nullptr;
	}
	return pBlackMarketView;
}

void BlackMarketView::show()
{
	GameInfoView::show();
	// ˢ���б���ʾ
	updateShowList(m_pBlackMarket);
	// ��ʾ���н��׹��ܲ˵��б�
	showMenu();
}

void BlackMarketView::updateShowList(BlackMarket* pMarket)
{
	// ʵ����Ϸ������Ϣ
	GameInfoView::show();
	// ������Ʒ�б���ʾ
	cout << "����ǰ����" << pMarket->GetName() << "�ĺ��н�����,���պ�����Ʒ����:" << endl;
	vector<GameItem*>* pItemList = pMarket->getItemList();
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
}

void BlackMarketView::showMenu()
{
	cout << string(80, '*') << endl;
	string choice;
	cin >> choice;
	




}
