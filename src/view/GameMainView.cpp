///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-03-26 22:57
/// @Mail		: 3453851623@qq.com
/// @Brief		: 
///****************************************************************************

#include "GameMainView.h"
#include "RailStationView.h"

GameMainView::GameMainView()
{
}

GameMainView::~GameMainView()
{
}

void GameMainView::show()
{
	GameInfoView::show();
    showMain();
}

void GameMainView::showMain()
{
    // ��ȡ���������Ƽ���
    GameModel* gameModel = GameModel::getInstance();
    vector<GameScene*>* gameScenes = gameModel->getGameScenes();
    vector<string> sceneNames;
    for (GameScene* gameScene : *gameScenes)
        sceneNames.push_back(gameScene->GetName());
    sceneNames.push_back("��ʼ�µ�һ��");
    sceneNames.push_back("������Ϸ");

    // ����chooseItemInMenu������������ѡ��
    switch (chooseItemInMenu("���е���ʾ��ͼ", sceneNames))
    {
    case 1:
    {
        // ����վ
        RailStationView* stationView = new RailStationView();
        stationView->show();
        delete stationView;
        break;
    }
    case 2:
    {
        // ����
        int tmp = 1;
        break;
    }
    case 3:
    {
        // �ʾ�
        break;
    }
    case 4:
    {
        // ҽԺ
        break;
    }
    case 5:
    {
        // ����
        break;
    }
    case 6:
    {
        // �ⷿ�н�
        break;
    }
    case 7:
    {
        // ����
        break;
    }
    case 8:
    {
        // ��ʼ�µ�һ��
        break;
    }
    case 9:
    {
        // �˳���Ϸ
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
    // �˵�����
    cout << menuName << endl;
    for (int i = 0; i < itemNames.size(); ++i)
        cout << i + 1 << "." << itemNames[i] << endl;
    cout << "���������ѡ��";
    int opt;
    cin >> opt;
    return opt;
}