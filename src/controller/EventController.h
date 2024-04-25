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
	EventController(const EventController& eventController) = delete;				// 禁用拷贝构造
	EventController& operator=(const EventController& enventController) = delete;	// 禁用拷贝赋值操作重载函数
	static EventController* getInstance();
	virtual ~EventController();

	// 加载事件数据
	void LoadingData();
	
	// 处理触发后的业务逻辑：影响物品价格或者角色拥有物品数量 广播消息
	void WallMessage(int nEventId);


private:
	EventController();
	static EventController* s_instance;
};

