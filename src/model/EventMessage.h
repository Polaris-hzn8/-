///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-04-16 22:57
/// @Mail		: 3453851623@qq.com
/// @Brief		: 影响物品价格和数量的消息数据模型
///****************************************************************************

#pragma once

#include <iostream>
using namespace std;

class EventMessage
{
public:
	EventMessage();
	virtual ~EventMessage();

	int GetId() { return m_nId; }
	void SetId(int nId) { m_nId = nId; }
	int GetGoodsId() { return m_nGoodsId; }
	void SetGoodstId(int nGoodsId) { m_nGoodsId = nGoodsId; }
	int GetPriceInc() { return m_nPriceInc; }
	void SetPriceInc(int nPriceInc) { m_nPriceInc = nPriceInc; }
	int GetPriceDec() { return m_nPriceDec; }
	void SetPriceDec(int nPriceDec) { m_nPriceDec = nPriceDec; }
	int GetGoodsCount() { return m_nGoodsCount; }
	void SetGoodsCount(int nGoodsCount) { m_nGoodsCount = nGoodsCount; }
	string GetContent() { return m_strContent; }
	void SetContent(string strContent) { m_strContent = strContent; }

private:
	int		m_nId;
	int		m_nGoodsId;
	int		m_nPriceInc;
	int		m_nPriceDec;
	int		m_nGoodsCount;
	string	m_strContent;
};

