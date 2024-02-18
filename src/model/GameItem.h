///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <string>
using namespace std;

class GameItem {
public:
	GameItem();
	~GameItem();

	void SetId(int id) { m_id = id; }
	int GetId() { return m_id; }

	void SetName(string name) { m_name = name; }
	string GetName() { return m_name; }

	void SetInPrice(int inPrice) { m_inPrice = inPrice; }
	int GetInPrice() { return m_inPrice; }

	void SetOutPrice(int outPrice) { m_outPrice = outPrice; }
	int GetOutPrice() { return m_outPrice; }

	void SetMinPrice(int minPrice) { m_minPrice = minPrice; }
	int GetMinPrice() { return m_minPrice; }

	void SetMaxPrice(int maxPrice) { m_maxPrice = maxPrice; }
	int GetMaxPrice() { return m_maxPrice; }

	void SetCount(int count) { m_count = count; }
	int GetCount() { return m_count; }

private:
	int		m_id;			//��Ʒ���
	string	m_name;			//��Ʒ����
	int		m_inPrice;		//��Ʒ�����۸�
	int		m_outPrice;		//��Ʒ���ۼ۸�
	int		m_minPrice;		//��Ʒ������С�۸�
	int		m_maxPrice;		//��Ʒ�������۸�
	int		m_count;		//��Ʒ����
};

