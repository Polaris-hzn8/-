///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "SoundController.h"

SoundController* SoundController::s_instance = nullptr;

SoundController* SoundController::getInstance()
{
    if (!s_instance) {
        s_instance = new SoundController();
    }
    return s_instance;
}

SoundController::SoundController()
{
    m_slience = false;
}

SoundController::~SoundController()
{
}

void SoundController::playSound(int id)
{
    if (m_slience) {
        return;
    }
    /*
        mci ý����ƽӿ� ����MPEG AVI MP3 �� ID��
        mciSendString(LPCWSTR lpszCommand, LPWSTR lpszReturnString, UNIT cchReturn, HANDLE hwndCallback)
        ����1��LPCWSTR lpszCommand         �����ַ������� open��play ��close��
        ����2��LPTSTR lpszReturnString     ���ܷ�����Ϣ���ַ��� �����ַ���
        ����3��UINT cchReturn              �����ַ����Ĵ�С��sizeof
        ����4��HANDLE hwndCallback         �ص����ھ����һ������ΪNULL
    */
    //string command = "play res/";
    //command += id;
    //command += ".mp3";
    //mciSendStringA(command.c_str(), 0, 0, NULL);
    stringstream ss;
    ss << "play res/";
    ss << id;
    ss << ".mp3";
    mciSendStringA(ss.str().c_str(), 0, 0, NULL);
}

void SoundController::stopSound(int id)
{
    stringstream ss;
    ss << "stop res/";
    ss << id;
    ss << ".mp3";
    mciSendStringA(ss.str().c_str(), 0, 0, NULL);
}

/**
     * PlaySound��Windows���ڲ������ֵ�API���� ֻ�ܲ���.wav��ʽ����Ƶ
     * ����1��Ҫ�����������ַ�������Ƶ�ļ�·����
     * ����2��Ӧ�ó����ʵ����� NULL
     * ����3����־���
     *  SND_ASYNC       �첽��ʽ����
     *  SND_FILENAME    ָ��WAVE�ļ���
     *  SND_LOOP        �ظ���������
     *  ֱ�Ӵ�����ַ�����ʾֹͣ����
     */
void SoundController::playBGM()
{
    if (m_slience) {
        return;
    }
    PlaySound(TEXT("res/bgm.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);
}

void SoundController::stopBGM()
{
    PlaySound(NULL, NULL, SND_FILENAME);
}

//ֹͣ������������
void SoundController::stopAll()
{
    stopBGM();//ֹͣ���ű�������
    vector<int> soundIds = { 1001 };
    for (int i = 0; i < soundIds.size(); ++i) {
        stopSound(soundIds[i]);
    }
}

bool SoundController::getSlience()
{
    return m_slience;
}

bool SoundController::setSlience(bool silence)
{
    m_slience = silence;
    return true;
}
