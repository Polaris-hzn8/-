///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <iostream>
#include "Model/BlackMarket.h"
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
    GameCore(const GameCore& gameCore) = delete;                 // ���ÿ������캯��
    GameCore& operator=(const GameCore& gameCore) = delete;      // ���ÿ�����ֵ�������غ���
    static GameCore* getInstance();
    virtual ~GameCore();

    void start();       // ��Ϸ��ʼ
    void finish();      // ��Ϸ����

private:
    void logicUpdate();                         // �߼�ˢ��
    void MarketListUpdate(BlackMarket *market); // ������Ʒ���ݸ���
    void screenUpdate();                        // ��ʾˢ��

    bool m_bGameRuning;                         // ��Ϸ��ѭ������״̬

    GameCore();
    static GameCore* s_instance;
};


