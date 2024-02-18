///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <vector>
#include <string>
#include "GameItem.h"
using namespace std;

class BlackMarket
{
public:
	BlackMarket();
	~BlackMarket();

	void SetId(int id) { m_id = id; }
	int GetId() { return m_id; }

	void SetName(string name) { m_name = name; }
	string GetName() { return m_name; }

	vector<GameItem*>* getItemList() { return &m_itemList; }

private:
	int					m_id;		// ����id
	string				m_name;		// ��������
	vector<GameItem*>	m_itemList;	// ������Ʒ�б�
};

