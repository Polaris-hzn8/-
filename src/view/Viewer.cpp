///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "Viewer.h"

Viewer* Viewer::s_instance = nullptr;

Viewer* Viewer::getInstance()
{
    if (!s_instance) {
        s_instance = new Viewer();
    }
    return s_instance;
}

Viewer::Viewer()
{
}

Viewer::~Viewer()
{
}

void Viewer::showEntryAnimation()
{
    // ���Ŵ�����Ч
    SoundController::getInstance()->playSound(1001);
    // ��������
    vector<string> sentences = {
        "**********************************************************************************",
        "                               ���и����ռǵĹ���",
        "**********************************************************************************",
        "    ������һλ����ص�����ı�������꣬һ��ʼ��ֻ��2000Ԫ�����һ�Ƿ�峤��һ����åͷ",
        "�ӣ�5500Ԫ��ծ����Щծ��ÿ�����Ϣ�ߴ�10%���������ʱ���壬�峤����������������",
        "�������������ܻ�������������ͷ�����������������������е���������Ʒ�������¸���������",
        "��ծ����һ�Ҫ�ٵǸ������а�",
        "    ��ֻ���ڳ��д�100�죬ÿ�α���һ��������1�죬�տ�ʼ����ķ���ֻ�ܷ�100����������",
        "�������������������¼�������Ҫ����å��С͵�����֡�̰�١�ƭ�ӵȶ��Ƕ��£�����Ҫ������",
        "���ӵ���Ȼ�������跨����������",
        "    ���������ڳ���������VCD����˽�����Ĵ̼����Լ��������ʱ�����еĸ�Ц�¼���     ",
        "**********************************************************************************"
    };
    for (int i = 0; i < sentences.size(); ++i) {
        // ���Ŵ��ֶ���Ч��
        if (i < 3 || i == (sentences.size() - 1)) {
            cout << sentences[i] << endl;
        } else {
            playTypeWrite(sentences[i]);
        }
    }
    // ֹͣ���Ŵ�����Ч
    SoundController::getInstance()->stopSound(1001);
}

void Viewer::playTypeWrite(string line)
{
    int speed = 10; // ms
    for (int i = 0; i < line.length(); ++i) {
        cout << line[i];
        if (line[i] == ' ') {
            continue;
        } else {
            Sleep(speed);
        }
    }
    cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////mainMenu()
void Viewer::showMenu()
{
    string menuName = "��ӭ���������и����ռǡ���";
    vector<string> itemNames;
    itemNames.push_back("��Ϸ�˵�");
    itemNames.push_back("����ѡ��");
    itemNames.push_back("����");
    switch (chooseItemInMenu(menuName, itemNames)) {
    case 1:
        showGameMenu();     // ��Ϸ�˵�
        break;
    case 2:
        showSceneMenu();    // �����˵�
        break;
    case 3:
        showHelpMenu();     // �����˵�
        break;
    default:
        cout << "��������������ѡ��!~";
        Sleep(1000);
        system("cls");
        showMenu();
        break;
    }
}

void Viewer::showTime(int curTime, int maxTime)
{
    cout << "curTime:" << curTime << "/maxTime" << maxTime << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////��Ϸ�˵�
void Viewer::showGameMenu()
{
    system("cls");
    string menuName = "���˵�->��Ϸ�˵�";
    vector<string> itemNames;
    itemNames.push_back("����Ϸ");
    itemNames.push_back("�������а�");
    itemNames.push_back("��Ϸ����");
    itemNames.push_back("����");
    switch (chooseItemInMenu(menuName, itemNames)) {
    case 1:
        // ����Ϸ
        GameCore::getInstance()->startGame();
        break;
    case 2:
        // �������а�
        showGameRank();
        break;
    case 3:
        // ��Ϸ����
        showGameSetting();
        break;
    case 4:
        // ����
        system("cls");
        showMenu();
        break;
    default:
        cout << "��������������ѡ��!~";
        Sleep(1000);
        system("cls");
        showGameMenu();
        break;
    }
}

void Viewer::showGameRank()
{

}

void Viewer::showGameSetting()
{
    SoundController* sdctl = SoundController::getInstance();
    bool slience = sdctl->getSlience();

    system("cls");
    string menuName = "���˵�->��Ϸ�˵�->��Ϸ����";
    vector<string> itemNames;
    if (slience) {
        itemNames.push_back("������Ч");
    } else {
        itemNames.push_back("�ر���Ч");
    }
    itemNames.push_back("����ڿ͹�����������");
    itemNames.push_back("����");
    switch (chooseItemInMenu(menuName, itemNames)) {
    case 1:
        // ��Ч����
        sdctl->setSlience(!slience);
        // ִ����Ч����
        if (slience) {
            sdctl->playBGM();
        } else {
            sdctl->stopAll();
        }
        showGameSetting();
        break;
    case 2: 
        // ����ڿ͹�����������
        break;
    case 3:
        // ����
        system("cls");
        showGameMenu();
        break;
    default:
        cout << "��������������ѡ��!~";
        Sleep(1000);
        showGameSetting();
        break;
    }
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////�����˵�
void Viewer::showSceneMenu()
{
    string menuName = "���˵�->�����˵�";
    vector<string> itemNames;
    itemNames.push_back("����Ϸ");
    itemNames.push_back("�������а�");
    itemNames.push_back("��Ϸ����");
    itemNames.push_back("�˳���Ϸ");
    switch (chooseItemInMenu(menuName, itemNames)) {
    case 1:
        // ����Ϸ

        break;
    case 2:
        // �������а�
        break;
    case 3:
        // ��Ϸ����
        break;
    case 4:
        // �˳���Ϸ
        break;
    default:
        break;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////�����˵�
void Viewer::showHelpMenu()
{
    string menuName = "���˵�->�����˵�";
    vector<string> itemNames;
    itemNames.push_back("����Ϸ");
    itemNames.push_back("�������а�");
    itemNames.push_back("��Ϸ����");
    itemNames.push_back("�˳���Ϸ");
    switch (chooseItemInMenu(menuName, itemNames)) {
    case 1:
        // ����Ϸ

        break;
    case 2:
        // �������а�
        break;
    case 3:
        // ��Ϸ����
        break;
    case 4:
        // �˳���Ϸ
        break;
    default:
        break;
    }
}



int Viewer::chooseItemInMenu(string menuName, vector<string> itemNames)
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
