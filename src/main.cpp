///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include <string>
#include <sstream>
#include <iostream>
#include <windows.h>
#include "Model/GameModel.h"
#include "Controller/GameController.h"

extern void setTitle(std::string title);
extern void setColor(char bgColor, char fgColor);
extern void setWinSize(int width, int height);

// ���ô�������
void setTitle(std::string title)
{
    std::stringstream cmd;
    cmd << "title ";
    cmd << title;
    // ����title + ��������
    system(cmd.str().c_str());
}

// ���ô�����ɫ
void setColor(char bgColor, char fgColor)
{
    std::stringstream cmd;
    cmd << "color ";
    cmd << bgColor;
    cmd << fgColor;
    system(cmd.str().c_str());
}

// ���ô����С
void setWinSize(int width, int height)
{
    std::stringstream cmd;
    cmd << "mode con ";
    cmd << "cols=" << width;
    cmd << "lines=" << height;
    system(cmd.str().c_str());
}

int main()
{
    // ����̨��������
    setTitle("My leaf life record.");   // ���ñ���
    //setWinSize(80, 80);                 // ���ô���Ĵ�С
    //setColor('8', 'F');                 // ���ñ���ɫ��ǰ��ɫ

    // ��ȡ��Ϸ�������ĵ�������
    GameController::getInstance()->start();

    system("pause");
    return 0;
}
