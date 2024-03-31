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
		m_market->SetId(m_id);			// 地铁站id等于黑市id
		m_market->SetName(m_name);		// 地铁站name等于黑市name
	}
	return m_market;
}

