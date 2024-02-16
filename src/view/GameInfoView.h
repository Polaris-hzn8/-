///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <iostream>
using namespace std;

class GameInfoView
{
public:
	GameInfoView();
	~GameInfoView();
protected:
	virtual void showGameInfo();
private:
	void showTime(int curTime, int maxTime);// չʾ��Ϸʱ��
	void showEvent();						// չʾ����¼�
	void showRoleInfo();					// չʾ��ҽ�ɫ����
	int m_pcurTime;
	int m_pmaxTime;
};
