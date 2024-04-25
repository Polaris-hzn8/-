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
    int width = 62;
    cout << string(width, '-') << endl;
    cout << "��������" << endl;
    cout << string(width, '-') << endl;

    EventMessage* pCurEventMessage = GameModel::getInstance()->getCurEventMessage();
    if (pCurEventMessage)
    {
        cout << pCurEventMessage->GetContent() << endl;
    }
    else
    {
        cout << "����ƽ����һ�죬û���¼�����......" << endl;
    }


    cout << string(width, '-') << endl;
}

void GameInfoView::showRoleInfo()
{
    int width = 62;
    cout << string(width, '*') << endl;

    // ��װ�ַ���str
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
    roleInfos.push_back("�����Ϣ:");
    roleInfos.push_back(formatString(1, "�ֽ�", m_pRole->GetCash(), "Ԫ", width));
    roleInfos.push_back(formatString(2, "���", m_pRole->GetDeposit(), "Ԫ", width));
    roleInfos.push_back(formatString(3, "��ծ", m_pRole->GetDebt(), "Ԫ", width));
    roleInfos.push_back(formatString(4, "����", m_pRole->GetHealth(), "HP", width));
    roleInfos.push_back(formatString(5, "����", m_pRole->GetFame(), "FM", width));
    for (string str:roleInfos)
        cout << str << endl;

    cout << string(width, '*') << endl;
}

