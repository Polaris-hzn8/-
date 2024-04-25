///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-03-26 22:57
/// @Mail		: 3453851623@qq.com
/// @Brief		: 
///****************************************************************************

#include "GameInfoView.h"

GameInfoView::GameInfoView()
{
    m_curTime = 0;
    m_maxTime = 0;
    m_pRole = nullptr;
}

GameInfoView::~GameInfoView()
{
}

int GameInfoView::chooseItemInMenu(string menuName, vector<string> itemNames)
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

void GameInfoView::show()
{
    system("cls");
    GameModel* gameModel = GameModel::getInstance();
    m_curTime = gameModel->getCurTime();
    m_maxTime = gameModel->getMaxTime();
    m_pRole = gameModel->getRole();
    // 显示时间
    showTime();
    // 显示随机事件
    showEvent();
    // 显示角色信息
    showRoleInfo();
}

void GameInfoView::showTime()
{
    if (m_curTime == 1) {
        cout << "您开启了浮生之旅！" << endl;
    }
    cout << "curTime:day" << m_curTime << "/maxTime:day" << m_maxTime << endl;
}

void GameInfoView::showEvent()
{
    int width = 62;
    cout << string(width, '-') << endl;
    cout << "今日新闻" << endl;
    cout << string(width, '-') << endl;

    EventMessage* pCurEventMessage = GameModel::getInstance()->getCurEventMessage();
    if (pCurEventMessage)
    {
        cout << pCurEventMessage->GetContent() << endl;
    }
    else
    {
        cout << "又是平静的一天，没有事件发生......" << endl;
    }


    cout << string(width, '-') << endl;
}

void GameInfoView::showRoleInfo()
{
    int width = 62;
    cout << string(width, '*') << endl;

    // 组装字符串str
    auto formatString = [](int nId, string strItemName, int nValue, string strUnit, int nWidth)
    {
        int width = 62;

        char space = ' ';
        string space_n1(6 - strItemName.length(), ' ');
        string space_n2(3, ' ');
        string space_n3(12 - to_string(nValue).length(), ' ');

        char buff[1024];
        sprintf_s(buff, "*  %d.%s%s:%s%d%s%s", nId, strItemName.c_str(),
            space_n1.c_str(), space_n2.c_str(), nValue, space_n3.c_str(), strUnit.c_str());

        return string(buff);
    };
    
    vector<string> roleInfos;
    roleInfos.push_back("玩家信息:");
    roleInfos.push_back(formatString(1, "现金", m_pRole->GetCash(), "元", width));
    roleInfos.push_back(formatString(2, "存款", m_pRole->GetDeposit(), "元", width));
    roleInfos.push_back(formatString(3, "负债", m_pRole->GetDebt(), "元", width));
    roleInfos.push_back(formatString(4, "健康", m_pRole->GetHealth(), "HP", width));
    roleInfos.push_back(formatString(5, "名声", m_pRole->GetFame(), "FM", width));
    for (string str:roleInfos)
        cout << str << endl;

    cout << string(width, '*') << endl;
}

