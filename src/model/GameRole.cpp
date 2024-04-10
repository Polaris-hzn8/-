///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "GameRole.h"

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
