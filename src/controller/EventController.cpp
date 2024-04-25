///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-04-15 22:57
/// @Mail		: 3453851623@qq.com
/// @Brief		: 
///****************************************************************************

#include "Model/GameModel.h"
#include "Model/EventMessage.h"
#include "EventController.h"

#define GAME_MESSAGE_COUNT 3

typedef struct Message
{
    string	content;		// ��Ϣ����
    int		goodsId;		// Ӱ�����Ʒ���
    int		priceInc;		// ��Ʒ�۸����ӱ���
    int		priceDec;		// ��Ʒ�۸���ٱ���
    int		goodsCount;		// �����������ӻ����
};

Message MessageConfig[GAME_MESSAGE_COUNT] =
{
    {"ר��������ߴ�ѧ���������ʣ�����������ܻ�ӭ��", 4, 2, 0, 0},
    {"���ŵ���ͬѧ������������˽���������ˣ�����", 1, 0, 0, 2},
    {"�г��ϳ�������Ը�������˽����", 0, 0, 8, 0},
};

EventController::EventController()
{

}

EventController::~EventController()
{
}

void EventController::LoadingData()
{
    map<int, EventMessage*>* pMapGameMessages = GameModel::getInstance()->getGameMessages();
    for (int i = 0; i < GAME_MESSAGE_COUNT; ++i)
    {
        Message iMessageConfig = MessageConfig[i];
        EventMessage *pEventMessage = new EventMessage();
        pEventMessage->SetId(i);
        pEventMessage->SetGoodstId(iMessageConfig.goodsId);
        pEventMessage->SetContent(iMessageConfig.content);
        pEventMessage->SetPriceInc(iMessageConfig.priceInc);
        pEventMessage->SetPriceDec(iMessageConfig.priceDec);
        pEventMessage->SetGoodsCount(iMessageConfig.goodsCount);
        pair<int, EventMessage*> pair_tmp = make_pair(pEventMessage->GetId(), pEventMessage);
        pMapGameMessages->insert(pair_tmp);
    }
}

void EventController::WallMessage()
{
}
