///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <string>
#include "BlackMarket.h"
using namespace std;

class RailStation
{
public:
	RailStation();
	~RailStation();

	int GetId() { return m_id; }
	void SetId(int val) { m_id = val; }
	string GetName() { return m_name; }
	void setName(string name) { m_name = name; }

	BlackMarket* getMarket();
private:
	int				m_id;
	string			m_name;
	BlackMarket*	m_market;
};

