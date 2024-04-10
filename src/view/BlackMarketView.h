///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-03-26 22:57
/// @Mail		: 3453851623@qq.com
/// @Brief		: 游戏黑市商店界面视图类
///****************************************************************************

#pragma once

#include "GameInfoView.h"
#include "Model/BlackMarket.h"

/**
 * 构建模式：
 * 1.单例类只能有一个实例
 * 2.单例类必须自己创建唯一实例
 * 3.单例类必须给所有其他对象提供这个一个实例
 */

class BlackMarketView : public GameInfoView
{
public:
	// 构建黑市界面实例
	static BlackMarketView* create(BlackMarket* pMarket);
	virtual ~BlackMarketView();

	void show() override;

protected:
	BlackMarketView();

private:
	// 商品和货物列表的刷新显示
	void showMarketList(BlackMarket* pMarket);
	// 黑市交易功能菜单列表
	void showOptionMenu();
	// 黑市对象数据
	BlackMarket* m_pBlackMarket;
};

