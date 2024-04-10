///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-03-26 22:57
/// @Mail		: 3453851623@qq.com
/// @Brief		: 
///****************************************************************************

#include "Windows.h"
#include "GameMenuView.h"
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
	// ��ʾ������Ʒ�б�
	showMarketList(m_pBlackMarket);
	// ��ʾ���н��׹��ܲ˵��б�
	showOptionMenu();
}

void BlackMarketView::showMarketList(BlackMarket* pMarket)
{
	// ʵ����Ϸ������Ϣ
	GameInfoView::show();
	// ������Ʒ�б���ʾ
	cout << "����ǰ����" << pMarket->GetName() << "�ĺ��н�����,���պ�����Ʒ����:" << endl;
	vector<GameItem*>* pItemList = pMarket->getItemList();
	for (int i = 0; i < pItemList->size(); ++i)
	{
		GameItem* gameItem = (*pItemList)[i];
		int nItemId = gameItem->GetId();					// ��ƷId
		string strItemName = gameItem->GetName();			// ��Ʒ����
		int nOutPrice = gameItem->GetOutPrice();			// ��Ʒ���ۼ۸�
		int nCount = gameItem->GetCount();					// ��Ʒʣ������

		char space = ' ';
		string strOutPrice = to_string(nOutPrice);
		string space_n1(15 - strItemName.length(), ' ');
		string space_n2(6 - strOutPrice.length(), ' ');

		char buff[1024];
		sprintf_s(buff, "%d.%s%sPrice:%d%s$ Remains:%d", nItemId, strItemName.c_str(), space_n1.c_str(), nOutPrice, space_n2.c_str(), nCount);
		cout << buff << endl;
	}

	cout << string(80, '*') << endl;

	// ��ҳ����ݻ����б�չʾ
	GameRole* playerInfo = GameModel::getInstance()->getRole();
	vector<GameItem*>* playerGoods = playerInfo->GetDepotItems();
	int nCurDepotUse = playerInfo->GetCurDepotUse();
	int nMaxDepotCapa = playerInfo->GetMaxDepotCapa();
	char buff[1024];
	sprintf_s(buff, "�����ݻ����б�����(%d/%d):", nCurDepotUse, nMaxDepotCapa);
	cout << buff << endl;
	if (nCurDepotUse == 0)
	{
		cout << "����һ��" << endl;
	}
	else
	{
		for (int i = 0; i < playerGoods->size(); ++i)
		{
			GameItem* gameItem = (*playerGoods)[i];
			int nItemId = gameItem->GetId();					// ��ƷId
			string strItemName = gameItem->GetName();			// ��Ʒ����
			int nInPrice = gameItem->GetInPrice();				// ��Ʒ����ƽ���۸�
			int nCount = gameItem->GetCount();					// ��Ʒʣ������

			char space = ' ';
			string strInPrice = to_string(nInPrice);
			string space_n1(15 - strItemName.length(), ' ');
			string space_n2(6 - strInPrice.length(), ' ');

			char buff[1024];
			sprintf_s(buff, "%d.%s%sInPrice:%d%s$ Remains:%d", nItemId, strItemName.c_str(), space_n1.c_str(), nInPrice, space_n2.c_str(), nCount);
			cout << buff << endl;
		}
	}
}

void BlackMarketView::showOptionMenu()
{
	cout << string(80, '*') << endl;
	vector<string> vetItemNames;
	vetItemNames.push_back("����");
	vetItemNames.push_back("����");
	vetItemNames.push_back("�뿪");

	string menuName = "��ѡ�����Ĳ���";
	int nType = chooseItemInMenu(menuName, vetItemNames);
	switch (nType)
	{
	case 1:// ������Ʒ
	{
		cout << "��Ҫ�������Ʒ�����:" << endl;
		int nGoodsId;
		cin >> nGoodsId;
		bool bIsItemExist = m_pBlackMarket->IsItemExist(nGoodsId);
		if (bIsItemExist)
		{
			cout << "��Ҫ�������Ʒ������:" << endl;
			int nGoodsNum;
			cin >> nGoodsNum;
			int nRet = m_pBlackMarket->SellItem(nGoodsId, nGoodsNum);
			switch (nRet)
			{
			case 0:
				cout << "���׳ɹ�!" << endl;
				break;
			case 1:
				cout << "����ʧ��!��Ʒ������!��������ȷ����Ʒ���!" << endl;
				break;
			case 2:
				cout << "����ʧ��!�������������̵�ʣ����Ʒ����!" << endl;
				break;
			case 3:
				cout << "����ʧ��!��������!" << endl;
				break;
			case 4:
				cout << "����ʧ��!���Ĳֿ���������!" << endl;
				break;
			}
		}
		else
		{
			cout << "��Ʒ��Ų����ڣ���������ȷ����Ʒ���!" << endl;
		}
		
		Sleep(1000 * 2);

		BlackMarketView::show();
		break;
	}
	case 2:// ������Ʒ
	{
		cout << "��Ҫ���۵���Ʒ�����:" << endl;
		string choice;
		cin >> choice;
		break;
	}
	case 3:// �뿪����
	{
		cout << "�����뿪�̵�..." << endl;
		Sleep(500);
		GameMenuView::getInstance()->EnterGameMainView();
	}
	default:
	{
		cout << "��������Ч�Ĳ�������!!!" << endl;
		Sleep(1000);
		BlackMarketView::show();
	}

	}
}
