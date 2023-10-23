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

void Viewer::showSystemMenu()
{
    // չʾ�˵�
    cout << "��ӭ���������и����ռǡ���" << endl;
    vector<string> itemNames;
    itemNames.push_back("ϵͳ");
    itemNames.push_back("����");
    itemNames.push_back("����");

    for (int i = 0; i < itemNames.size(); ++i) {
        cout << i + 1 << "." << itemNames[i] << endl;
    }
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
