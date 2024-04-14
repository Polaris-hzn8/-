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

// 构建模式
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
	// 显示黑市商品列表
	showMarketList(m_pBlackMarket);
	// 显示黑市交易功能菜单列表
	showOptionMenu();
}

void BlackMarketView::showMarketList(BlackMarket* pMarket)
{
	// 实现游戏基本信息
	GameInfoView::show();
	// 黑市商品列表显示
	cout << "您当前正在" << pMarket->GetName() << "的黑市交易所,今日黑市商品如下:" << endl;
	vector<GameItem*>* pItemList = pMarket->getItemList();
	for (int i = 0; i < pItemList->size(); ++i)
	{
		GameItem* gameItem = (*pItemList)[i];
		int nItemId = gameItem->GetId();					// 商品Id
		string strItemName = gameItem->GetName();			// 商品名称
		int nOutPrice = gameItem->GetOutPrice();			// 商品出售价格
		int nCount = gameItem->GetCount();					// 商品剩余数量

		char space = ' ';
		string strOutPrice = to_string(nOutPrice);
		string space_n1(15 - strItemName.length(), ' ');
		string space_n2(6 - strOutPrice.length(), ' ');

		char buff[1024];
		sprintf_s(buff, "%d.%s%sPrice:%d%s$ Remains:%d", nItemId, strItemName.c_str(), space_n1.c_str(), nOutPrice, space_n2.c_str(), nCount);
		cout << buff << endl;
	}

	cout << string(80, '*') << endl;

	// 玩家出租屋货物列表展示
	GameRole* playerInfo = GameModel::getInstance()->getRole();
	vector<GameItem*>* playerGoods = playerInfo->GetDepotItems();
	int nCurDepotUse = playerInfo->GetCurDepotUse();
	int nMaxDepotCapa = playerInfo->GetMaxDepotCapa();
	char buff[1024];
	sprintf_s(buff, "出租屋货物列表如下(%d/%d):", nCurDepotUse, nMaxDepotCapa);
	cout << buff << endl;
	if (nCurDepotUse == 0)
	{
		cout << "空无一物" << endl;
	}
	else
	{
		for (int i = 0; i < playerGoods->size(); ++i)
		{
			GameItem* gameItem = (*playerGoods)[i];
			int nItemId = gameItem->GetId();					// 商品Id
			string strItemName = gameItem->GetName();			// 商品名称
			int nInPrice = gameItem->GetInPrice();				// 商品购入平均价格
			int nCount = gameItem->GetCount();					// 商品剩余数量

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
	vetItemNames.push_back("购买");
	vetItemNames.push_back("出售");
	vetItemNames.push_back("离开");

	string menuName = "请选择您的操作";
	int nType = chooseItemInMenu(menuName, vetItemNames);
	switch (nType)
	{
	case 1:// 购买商品
	{
		cout << "您要购买的商品编号是:";
		int nGoodsId;
		cin >> nGoodsId;
		GameItem* pGameItem = nullptr;
		pGameItem = m_pBlackMarket->GetItemFromMarket(nGoodsId);
		if (pGameItem)
		{
			cout << "您要购买的商品数量是:";
			int nGoodsNum;
			cin >> nGoodsNum;
			int nRet = m_pBlackMarket->SellItem(nGoodsId, nGoodsNum);
			switch (nRet)
			{
			case 0:
				cout << "交易成功!" << endl;
				break;
			case 1:
				cout << "交易失败!商品不存在!请输入正确的商品编号!" << endl;
				break;
			case 2:
				cout << "交易失败!购买数量大于商店剩余商品数量!" << endl;
				break;
			case 3:
				cout << "交易失败!您的余额不足!" << endl;
				break;
			case 4:
				cout << "交易失败!您的仓库容量不足!" << endl;
				break;
			}
		}
		else
		{
			cout << "商品编号不存在，请输入正确的商品编号!" << endl;
		}
		
		Sleep(1000 * 0.5);

		BlackMarketView::show();
		break;
	}
	case 2:// 出售商品
	{
		cout << "您要出售的商品编号是:";
		int nGoodsId;
		cin >> nGoodsId;
		GameItem* pStoreItem = nullptr;
		pStoreItem = m_pBlackMarket->GetItemFromMarket(nGoodsId);
		if (pStoreItem)
		{
			cout << "您需要出售的商品数量是:";
			int nGoodsNum;
			cin >> nGoodsNum;
			GameRole *pCurPlayer = GameModel::getInstance()->getRole();
			int nRet = pCurPlayer->SellItem(nGoodsId, nGoodsNum, pStoreItem->GetOutPrice());
			switch (nRet)
			{
			case 0:
				cout << "交易成功!" << endl;
				break;
			case 1:
				cout << "交易失败!仓库中不存在该商品!请输入正确的商品编号!" << endl;
				break;
			case 2:
				cout << "交易失败!仓库中对应的货物数量不足!" << endl;
				break;
			}
		}
		else
		{
			cout << "商品编号不存在，请输入正确的商品编号!" << endl;
		}

		Sleep(1000 * 0.5);

		BlackMarketView::show();
		break;
	}
	case 3:// 离开黑市
	{
		cout << "正在离开商店..." << endl;
		Sleep(1000 * 0.5);
		GameMenuView::getInstance()->EnterGameMainView();
		break;
	}
	default:
	{
		cout << "请输入有效的操作类型!!!" << endl;
		Sleep(1000 * 0.5);
		BlackMarketView::show();
	}

	}
}
