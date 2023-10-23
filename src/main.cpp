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
    // 1.控制台参数设置
    setTitle("My leaf life record.");   // 设置标题
    //setWinSize(80, 80);                 // 设置窗体的大小
    //setColor('8', 'F');                 // 设置背景色与前景色

    // 2.获取游戏控制器的单例对象
    GameController::getInstance()->start();

    system("pause");
    return 0;
}

void setTitle(string title)
{
    stringstream cmd;
    cmd << "title ";
    cmd << title;
    // 命令title + 标题名称
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
