///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-04-15 22:57
/// @Mail		: 3453851623@qq.com
/// @Brief		: 随机事件控制器类
///****************************************************************************

#pragma once

#include <iostream>
using namespace std;

class EventController
{
public:
	EventController();
	virtual ~EventController();

	// 加载事件数据
	void LoadingData();
	
	// 处理触发后的业务逻辑：影响物品价格或者角色拥有物品数量 广播消息
	void WallMessage();


private:


};

