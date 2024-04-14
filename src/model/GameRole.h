///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <vector>
#include "GameItem.h"
using namespace std;

class GameRole
{
public:
	GameRole();
	~GameRole();

	int GetCash() { return m_nCash; }
	void SetCash(int val) { m_nCash = val; }
	int GetDeposit() { return m_nDeposit; }
	void SetDeposit(int val) { m_nDeposit = val; }
	int GetDebt() { return m_nDebt; }
	void SetDebt(int val) { m_nDebt = val; }
	int GetHealth() { return m_nHealth; }
	void SetHealth(int val) { m_nHealth = val; }
	int GetFame() { return m_nFame; }
	void SetFame(int val) { m_nFame = val; }

	vector<GameItem*>* GetDepotItems() { return &m_pDepotItems; }
	int GetCurDepotUse() { return m_nCurDepotUse; }
	void SetCurDepotUse(int val) { m_nCurDepotUse = val; }
	int GetMaxDepotCapa() { return m_nMaxDepotCapa; }
	void SeMaxDepotCapa(int val) { m_nMaxDepotCapa = val; }
public:
	// 判断商品是否存在
	bool IsItemExist(int nGoodsId);
	// 游戏角色出售商品
	int SellItem(int nGoodsId, int nSellItemNum, int nCurPrice);
private:
	GameItem* GetItemFromDepot(int nGoodsId);
private:
	int m_nCash;		// 现金
	int m_nDeposit;		// 存款
	int m_nDebt;		// 负债
	int m_nHealth;		// 健康状况
	int m_nFame;		// 玩家名声

	vector<GameItem*> m_pDepotItems;	// 仓库中的货物
	int m_nCurDepotUse;					// 仓库已使用容量
	int m_nMaxDepotCapa;				// 仓库最大容量
};

