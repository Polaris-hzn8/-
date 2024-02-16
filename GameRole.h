///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

class GameRole
{
public:
	GameRole();
	~GameRole();

	int GetCash() { return m_cash; }
	int SetCash(int val) { m_cash = val; }
	int GetDeposit() { return m_deposit; }
	int SetDeposit(int val) { m_deposit = val; }
	int GetDebt() { return m_debt; }
	int SetDebt(int val) { m_debt = val; }
	int GetHealth() { return m_health; }
	int SetHealth(int val) { m_health = val; }
	int GetFame() { return m_fame; }
	int SetFame(int val) { m_fame = val; }
private:
	int m_cash;		// �ֽ�
	int m_deposit;	// ���
	int m_debt;		// ��ծ
	int m_health;	// ����״��
	int m_fame;		// �������
};

