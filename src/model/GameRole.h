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

	vector<GameItem*>* getGoods() { return &m_pItems; }
	int GetCurStoreUse() { return m_nCurStoreUse; }
	void SetCurStoreUse(int val) { m_nCurStoreUse = val; }
	int GetMaxStoreCapa() { return m_nMaxStoreCapa; }
	void SeMaxStoreCapa(int val) { m_nMaxStoreCapa = val; }

private:
	int m_nCash;		// �ֽ�
	int m_nDeposit;		// ���
	int m_nDebt;		// ��ծ
	int m_nHealth;		// ����״��
	int m_nFame;		// �������

	vector<GameItem*> m_pItems;	// �������еĻ���
	int m_nCurStoreUse;			// �ֿ���ʹ������
	int m_nMaxStoreCapa;		// �ֿ��������
};

