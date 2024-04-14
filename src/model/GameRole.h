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
	// �ж���Ʒ�Ƿ����
	bool IsItemExist(int nGoodsId);
	// ��Ϸ��ɫ������Ʒ
	int SellItem(int nGoodsId, int nSellItemNum, int nCurPrice);
private:
	GameItem* GetItemFromDepot(int nGoodsId);
private:
	int m_nCash;		// �ֽ�
	int m_nDeposit;		// ���
	int m_nDebt;		// ��ծ
	int m_nHealth;		// ����״��
	int m_nFame;		// �������

	vector<GameItem*> m_pDepotItems;	// �ֿ��еĻ���
	int m_nCurDepotUse;					// �ֿ���ʹ������
	int m_nMaxDepotCapa;				// �ֿ��������
};

