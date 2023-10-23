///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

class Viewer {
public:
    Viewer();
    virtual ~Viewer();
    static Viewer* getInstance();

public:
    void playEntryAnimation();
    void playTypeWrite(std::string line);

protected:
private:
    static Viewer* s_instance;
};

