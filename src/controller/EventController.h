///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-04-15 22:57
/// @Mail		: 3453851623@qq.com
/// @Brief		: ����¼���������
///****************************************************************************

#pragma once

#include <iostream>
using namespace std;

class EventController
{
public:
	EventController(const EventController& eventController) = delete;				// ���ÿ�������
	EventController& operator=(const EventController& enventController) = delete;	// ���ÿ�����ֵ�������غ���
	static EventController* getInstance();
	virtual ~EventController();

	// �����¼�����
	void LoadingData();
	
	// ���������ҵ���߼���Ӱ����Ʒ�۸���߽�ɫӵ����Ʒ���� �㲥��Ϣ
	void WallMessage(int nEventId);


private:
	EventController();
	static EventController* s_instance;
};

