///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

class Viewer {
public:
    Viewer();
    virtual ~Viewer();
    static Viewer* getInstance();

protected:
private:
    static Viewer* s_instance;
};
