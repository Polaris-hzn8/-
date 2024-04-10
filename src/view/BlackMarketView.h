///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-03-26 22:57
/// @Mail		: 3453851623@qq.com
/// @Brief		: ��Ϸ�����̵������ͼ��
///****************************************************************************

#pragma once

#include "GameInfoView.h"
#include "Model/BlackMarket.h"

/**
 * ����ģʽ��
 * 1.������ֻ����һ��ʵ��
 * 2.����������Լ�����Ψһʵ��
 * 3.�����������������������ṩ���һ��ʵ��
 */

class BlackMarketView : public GameInfoView
{
public:
	// �������н���ʵ��
	static BlackMarketView* create(BlackMarket* pMarket);
	virtual ~BlackMarketView();

	void show() override;

protected:
	BlackMarketView();

private:
	// ��Ʒ�ͻ����б��ˢ����ʾ
	void showMarketList(BlackMarket* pMarket);
	// ���н��׹��ܲ˵��б�
	void showOptionMenu();
	// ���ж�������
	BlackMarket* m_pBlackMarket;
};

