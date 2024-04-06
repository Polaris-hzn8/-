///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <iostream>
#include "View/GameMenuView.h"
#include "Model/GameModel.h"
#include "Model/BlackMarket.h"
#include "Controller/GameCore.h"
using namespace std;

/**
 * �������ģʽ(����ģʽ)��
 * 1.������ֻ����һ��ʵ��
 * 2.����������Լ�����Ψһʵ��
 * 3.�����������������������ṩ���һ��ʵ��
 */

class GameCore
{
public:
    GameCore();
    virtual ~GameCore();
    static GameCore* getInstance();

    void start();       // ��Ϸ��ʼ
    void finish();      // ��Ϸ����

private:
    void logicUpdate();                         // �߼�ˢ��
    void MarketListUpdate(BlackMarket *market); // ������Ʒ���ݸ���
    void screenUpdate();                        // ��ʾˢ��

    bool m_bGameRuning;     // ��Ϸ��ѭ������״̬
    static GameCore* s_instance;
};


