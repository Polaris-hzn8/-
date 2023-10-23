///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

class GameWorld {
public:
    GameWorld();
    virtual ~GameWorld();
    static GameWorld* getInstance();

protected:
private:
    static GameWorld* s_instance;
};
