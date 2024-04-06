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
	// 刷新列表显示
	updateShowList(m_pBlackMarket);
	// 显示黑市交易功能菜单列表
	showMenu();
}

void BlackMarketView::updateShowList(BlackMarket* pMarket)
{
	// 实现游戏基本信息
	GameInfoView::show();
	// 黑市商品列表显示
	cout << "您当前正在" << pMarket->GetName() << "的黑市交易所,今日黑市商品如下:" << endl;
	vector<GameItem*>* pItemList = pMarket->getItemList();
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
}

void BlackMarketView::showMenu()
{
	cout << string(80, '*') << endl;
	string choice;
	cin >> choice;
	




}
