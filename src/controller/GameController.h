///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include "View/GameMenuView.h"
#include "Controller/SoundController.h"

/**
 * �������ģʽ(����ģʽ)��
 * 1.������ֻ����һ��ʵ��
 * 2.����������Լ�����Ψһʵ��
 * 3.�����������������������ṩ���һ��ʵ��
 */

class GameController {
public:
    GameController();
    virtual ~GameController();
    static GameController* getInstance();

    void start();   //Ӧ�ÿ�ʼ
    void finish();  //Ӧ�ý���

protected:
private:
    static GameController* s_instance;
};
