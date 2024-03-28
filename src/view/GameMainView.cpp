///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "GameMainView.h"
#include "RailStationView.h"

GameMainView::GameMainView()
{
}

GameMainView::~GameMainView()
{
}

void GameMainView::showGameInfo()
{
	GameInfoView::showGameInfo();
	showChoice();
}

void GameMainView::showChoice()
{
    // 获取功能项名称集合
    GameModel* gameModel = GameModel::getInstance();
    vector<GameScene*>* gameScenes = gameModel->getGameScenes();
    vector<string> sceneNames;
    for (GameScene* gameScene : *gameScenes) {
        sceneNames.push_back(gameScene->GetName());
    }
    sceneNames.push_back("开始新的一天");
    sceneNames.push_back("结束游戏");

    // 调用chooseItemInMenu方法进行名称选择
    switch (chooseItemInMenu("城市地面示意图", sceneNames))
    {
    case 1:
    {
        // 地铁站
        RailStationView* stationView = new RailStationView();
        stationView->showGameInfo();
        break;
    }
    case 2:
    {
        // 银行
        break;
    }
    case 3:
    {
        // 邮局
        break;
    }
    case 4:
    {
        // 医院
        break;
    }
    case 5:
    {
        // 机场
        break;
    }
    case 6:
    {
        // 租房中介
        break;
    }
    case 7:
    {
        // 网吧
        break;
    }
    case 8:
    {
        // 开始新的一天
        break;
    }
    case 9:
    {
        // 退出游戏
        break;
    }
    default:
    {
        break;
    }
    }
}

int GameMainView::chooseItemInMenu(string menuName, vector<string> itemNames)
{
    // 菜单名称
    cout << menuName << endl;
    for (int i = 0; i < itemNames.size(); ++i) {
        cout << i + 1 << "." << itemNames[i] << endl;
    }
    cout << "请做出你的选择：";
    int opt;
    cin >> opt;
    return opt;
}