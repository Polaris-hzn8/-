///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "RailStation.h"

RailStation::RailStation()
{
	m_id = 0;
	m_name = "";
	m_market = nullptr;
}

RailStation::~RailStation()
{
	if (m_market) {
		delete m_market;
		m_market = nullptr;
	}
}

BlackMarket* RailStation::getMarket()
{
	if (!m_market) {
		m_market = new BlackMarket();
		m_market->SetId(m_id);			// ����վid���ں���id
		m_market->SetName(m_name);		// ����վname���ں���name
	}
	return m_market;
}

