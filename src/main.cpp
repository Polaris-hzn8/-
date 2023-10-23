///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "Model/GameWorld.h"
#include "Controller/GameController.h"
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
using namespace std;

extern void setTitle(string title);
extern void setColor(char bgColor, char fgColor);
extern void setWinSize(int width, int height);

int main()
{
    // 1.����̨��������
    setTitle("My leaf life record.");   // ���ñ���
    //setWinSize(80, 80);                 // ���ô���Ĵ�С
    //setColor('8', 'F');                 // ���ñ���ɫ��ǰ��ɫ

    // 2.��ȡ��Ϸ�������ĵ�������
    GameController::getInstance()->start();

    system("pause");
    return 0;
}

void setTitle(string title)
{
    stringstream cmd;
    cmd << "title ";
    cmd << title;
    // ����title + ��������
    system(cmd.str().c_str());
}   

void setColor(char bgColor, char fgColor)
{
    stringstream cmd;
    cmd << "color ";
    cmd << bgColor;
    cmd << fgColor;
    system(cmd.str().c_str());
}

void setWinSize(int width, int height)
{
    stringstream cmd;
    cmd << "mode con ";
    cmd << "cols=" << width;
    cmd << "lines=" << height;
    system(cmd.str().c_str());
}
