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
    GameController(const GameController& gameController) = delete;                 // ���ÿ������캯��
    GameController& operator=(const GameController& gameController) = delete;      // ���ÿ�����ֵ�������غ���
    static GameController* getInstance();
    virtual ~GameController();

    void start();   //Ӧ�ÿ�ʼ
    void finish();  //Ӧ�ý���

protected:
private:
    GameController();
    static GameController* s_instance;
};
