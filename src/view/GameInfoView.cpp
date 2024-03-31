///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
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
    // �˵�����
    cout << menuName << endl;
    for (int i = 0; i < itemNames.size(); ++i) {
        cout << i + 1 << "." << itemNames[i] << endl;
    }
    cout << "���������ѡ��";
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
    // ��ʾʱ��
    showTime();
    // ��ʾ����¼�
    showEvent();
    // ��ʾ��ɫ��Ϣ
    showRoleInfo();
}

void GameInfoView::showTime()
{
    if (m_curTime == 1) {
        cout << "�������˸���֮�ã�" << endl;
    }
    cout << "curTime:day" << m_curTime << "/maxTime:day" << m_maxTime << endl;
}

void GameInfoView::showEvent()
{
}

void printLine(int width)
{
    for (int i = 0; i < width; ++i) {
        cout << "*";
    }
    cout << endl;
}

string formatRoleProp(int id, string prop, int value, string unit = "")
{
    char buff[1024];
    sprintf_s(buff, "%d.%s:%d%s", id, prop.c_str(), value, unit.c_str());
    return string(buff);
}

void GameInfoView::showRoleInfo()
{
    int width = 62;
    printLine(width);
    vector<string> roleInfos;
    roleInfos.push_back("�����Ϣ��");
    roleInfos.push_back(formatRoleProp(1, "�ֽ�", m_pRole->GetCash(), "Ԫ"));
    roleInfos.push_back(formatRoleProp(2, "���", m_pRole->GetDeposit(), "Ԫ"));
    roleInfos.push_back(formatRoleProp(3, "��ծ", m_pRole->GetDebt(), "Ԫ"));
    roleInfos.push_back(formatRoleProp(4, "����", m_pRole->GetHealth(), "HP"));
    roleInfos.push_back(formatRoleProp(5, "����", m_pRole->GetFame(), "FM"));

    for (string str:roleInfos) {
        cout << "*  " << str << string(width - str.length() - 4, ' ') << "*" << endl;
    }

    printLine(width);
}

