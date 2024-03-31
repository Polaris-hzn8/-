///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include "model/GameModel.h"
#include "Model/GameRole.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GameInfoView
{
public:
	GameInfoView();
	~GameInfoView();
	// ��װ�˵�ѡ���б�
	int chooseItemInMenu(string menuName, vector<string> itemNames);
protected:
	virtual void show();
private:
	void showTime();		// չʾ��Ϸʱ��
	void showEvent();		// չʾ����¼�
	void showRoleInfo();	// չʾ��ҽ�ɫ����
	int m_curTime;
	int m_maxTime;
	GameRole* m_pRole;
};
