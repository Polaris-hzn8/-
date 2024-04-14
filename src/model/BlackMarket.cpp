///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "GameModel.h"
#include "BlackMarket.h"

BlackMarket::BlackMarket()
{
	m_id = 0;
	m_name = "";
}

BlackMarket::~BlackMarket()
{

}

/**
 * \brief 玩家购买商品
 * \param nGoodsId
 * \param nGoodsNum
 * \return 0交易成功 1商品不存在 2商品数量不足 3玩家金额不够 4玩家仓库容量不足
 */
int BlackMarket::SellItem(int nGoodsId, int nSellItemNum)
{
	GameItem* pStoreItem = GetItemFromMarket(nGoodsId);
	// 检查商品是否存在
	if (pStoreItem == nullptr)
		return 1;

	// 检查商品剩余数量是否足够
	int nStoreItemNum = pStoreItem->GetCount();
	if (nStoreItemNum < nSellItemNum)
		return 2;

	// 判断玩家的金钱是否足够
	GameRole* pGameRole = GameModel::getInstance()->getRole();
	int nBalance = pGameRole->GetCash();						// 余额
	int nCost = nSellItemNum * (pStoreItem->GetOutPrice());		// 花销
	if (nBalance < nCost)
		return 3;

	// 判断玩家的仓库空间剩余大小是否足够
	int nCurDepotUse = pGameRole->GetCurDepotUse();
	int	nMaxDepotCapa = pGameRole->GetMaxDepotCapa();
	if (nMaxDepotCapa < nCurDepotUse + nSellItemNum)
		return 4;

	// 修改商店数据
	pStoreItem->SetCount(nStoreItemNum - nSellItemNum);			// 物品数量修改

	// 修改玩家数据
	pGameRole->SetCash(nBalance - nCost);						// 玩家余额修改
	pGameRole->SetCurDepotUse(nCurDepotUse + nSellItemNum);

	///////////////////////////////////////////////////////////////////////////////////////////////////
	// 修改玩家仓库中的数据
	// 判断仓库中是否已有该物品 如果有则直接增加数量 否则重新创建对象并入队再增加数量
	int nCid = pStoreItem->GetId();
	GameItem* pDepotItem = nullptr;
	vector<GameItem*>* pDepotItems = pGameRole->GetDepotItems();
	for (GameItem* pDepotItemTmp : *pDepotItems)
	{
		int nDid = pDepotItemTmp->GetId();
		if (nDid == nCid)
		{
			pDepotItem = pDepotItemTmp;
			break;
		}
	}

	if (!pDepotItem)
	{
		// 物品不存在
		pDepotItem = new GameItem();
		pDepotItem->SetId(pStoreItem->GetId());
		pDepotItem->SetName(pStoreItem->GetName());
		pDepotItem->SetInPrice(pStoreItem->GetOutPrice());
		pDepotItem->SetCount(nSellItemNum);
		pDepotItems->push_back(pDepotItem);
	}
	else
	{
		// 物品已经存在
		// 增加仓库已存在物品数量
		int nDepotItemNum = pDepotItem->GetCount();
		int nDepotItemNumNew = nDepotItemNum + nSellItemNum;
		pDepotItem->SetCount(nDepotItemNumNew);
		// 重新计算该物品的购入均价
		int InPrice = pDepotItem->GetInPrice();
		int nCost = nSellItemNum * (pStoreItem->GetOutPrice());
		int InPriceAvg = ((InPrice * nDepotItemNum) + nCost) / nDepotItemNumNew;
		pDepotItem->SetInPrice(InPriceAvg);
	}

	return 0;
}

GameItem* BlackMarket::GetItemFromMarket(int nGoodsId)
{
	GameItem* pStoreItem = nullptr;
	for (GameItem* pStoreItemTmp : m_itemList)
	{
		int nId = pStoreItemTmp->GetId();
		if (nId == nGoodsId)
		{
			pStoreItem = pStoreItemTmp;
			break;
		}
	}
	return pStoreItem;
}