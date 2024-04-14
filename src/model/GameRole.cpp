///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "GameRole.h"
#include "GameModel.h"

GameRole::GameRole()
{
	m_nCash = 2000;
	m_nDeposit = 0;
	m_nDebt = 5500;
	m_nHealth = 100;
	m_nFame = 100;

	m_nCurDepotUse = 0;
	m_nMaxDepotCapa = 30;
}

GameRole::~GameRole()
{
}

/**
 * 判断商品是否存在
 * \param nGoodsId
 * \return
 */
bool GameRole::IsItemExist(int nGoodsId)
{
	GameItem* pDepotItem = GetItemFromDepot(nGoodsId);
	return (pDepotItem == nullptr) ? false : true;
}

/**
 * \brief 玩家出售商品
 * \param nGoodsId		商品Id
 * \param nSellItemNum	商品数量
 * \param nCurOutPrice	商品当前出售价格
 * \return 0交易成功 1仓库商品不存在 2仓库商品数量不足
 */
int GameRole::SellItem(int nGoodsId, int nSellItemNum, int nCurOutPrice)
{
	// 检查仓库内商品是否存在
	GameItem* pDepotItem = GetItemFromDepot(nGoodsId);
	if (pDepotItem == nullptr)
		return 1;

	// 检查商品剩余数量是否足够
	int nDepotItemNum = pDepotItem->GetCount();
	if (nDepotItemNum < nSellItemNum)
		return 2;

	// 修改玩家余额
	GameRole* pGameRole = GameModel::getInstance()->getRole();
	int nBalance = pGameRole->GetCash();						// 余额
	int nProfit = nSellItemNum * nCurOutPrice;					// 售出总金额
	pGameRole->SetCash(nBalance + nProfit);						// 玩家余额修改

	// 修改玩家仓库占用数量
	int nCurDepotUse = pGameRole->GetCurDepotUse();
	int	nMaxDepotCapa = pGameRole->GetMaxDepotCapa();
	pGameRole->SetCurDepotUse(nCurDepotUse - nSellItemNum);

	// 修改仓库存储物品数量
	if (nDepotItemNum == nSellItemNum)
	{// 该商品全部卖出
		vector<GameItem*>* pDepotItems = pGameRole->GetDepotItems();	// 商品出队
		// pDepotItems->erase(pDepotItem);
		// erase方法需要使用迭代器进行删除
		for (auto itor = pDepotItems->begin(); itor != pDepotItems->end(); ++itor)
		{
			if ((*itor)->GetId() == pDepotItem->GetId())
			{
				pDepotItems->erase(itor);
				break;
			}
		}
	}
	else
	{// 该商品仍有剩余
		pDepotItem->SetCount(nDepotItemNum - nSellItemNum);				// 物品数量修改
	}
	return 0;
}

GameItem* GameRole::GetItemFromDepot(int nGoodsId)
{
	GameItem* pDepotItem = nullptr;
	for (GameItem* pDepotItemTmp : m_pDepotItems)
	{
		int nId = pDepotItemTmp->GetId();
		if (nId == nGoodsId)
		{
			pDepotItem = pDepotItemTmp;
			break;
		}
	}
	return pDepotItem;
}

