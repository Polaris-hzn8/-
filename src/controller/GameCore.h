///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

class GameCore {
public:
    GameCore();
    virtual ~GameCore();
    static GameCore* getInstance();

public:
    void startGame();
    void gameOver();

private:
    void logicUpdate();     // Âß¼­Ë¢ÐÂ
    void screenUpdate();    // ÏÔÊ¾Ë¢ÐÂ

private:
    static GameCore* s_instance;
    bool m_gameState;
};