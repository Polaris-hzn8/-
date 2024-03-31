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

// 设置窗体名称
void setTitle(std::string title)
{
    std::stringstream cmd;
    cmd << "title ";
    cmd << title;
    // 命令title + 标题名称
    system(cmd.str().c_str());
}

// 设置窗体颜色
void setColor(char bgColor, char fgColor)
{
    std::stringstream cmd;
    cmd << "color ";
    cmd << bgColor;
    cmd << fgColor;
    system(cmd.str().c_str());
}

// 设置窗体大小
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
    // 控制台参数设置
    setTitle("My leaf life record.");   // 设置标题
    //setWinSize(80, 80);                 // 设置窗体的大小
    //setColor('8', 'F');                 // 设置背景色与前景色

    // 获取游戏控制器的单例对象
    GameController::getInstance()->start();

    system("pause");
    return 0;
}
