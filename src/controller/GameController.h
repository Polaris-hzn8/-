///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include "View/Viewer.h"
#include "Controller/SoundController.h"

/*
�������ģʽ(����ģʽ)��
1��������ֻ����һ��ʵ��
2������������Լ�����Ψһʵ��
3�������������������������ṩ���һ��ʵ��
*/

class GameController {
public:
    GameController();
    virtual ~GameController();
    static GameController* getInstance();

public:
    void start();   //��Ϸ��ʼ
    void finish();  //��Ϸ����

protected:
private:
    static GameController* s_instance;
};
