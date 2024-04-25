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

EventController* EventController::s_instance = nullptr;

typedef struct Message
{
    string	content;		// 消息内容
    int		goodsId;		// 影响的物品编号
    int		priceInc;		// 商品价格增加倍数
    int		priceDec;		// 商品价格减少倍数
    int		goodsCount;		// 货物数量增加或减少
};

Message MessageConfig[GAME_MESSAGE_COUNT] =
{
    {"专家提议提高大学生动手素质，进口玩具颇受欢迎！", 4, 2, 0, 0},
    {"厦门的老同学资助我两部走私汽车！发了！！！", 1, 0, 0, 2},
    {"市场上充斥着来自福建的走私香烟", 0, 0, 8, 0},
};

EventController::EventController()
{

}

EventController* EventController::getInstance()
{
    if (!s_instance)
    {
        s_instance = new EventController();
    }
    return s_instance;
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

void EventController::WallMessage(int nEventId)
{
    GameModel* pGameModel = GameModel::getInstance();
    EventMessage* pEventMessage = pGameModel->getGameMessages()->at(nEventId);
    if (pEventMessage)
    {
        pGameModel->setCurEventMessage(pEventMessage);
        // 随机事件发生
        // 修改玩家仓库中的货物数量
        int nChangeItemNums = pEventMessage->GetGoodsCount();
        if (nChangeItemNums > 0)
        {//仓库中货物数量增加
            GameRole* player = pGameModel->getRole();
            int nCurDepotUse = player->GetCurDepotUse();
            int nMaxDepotCapa = player->GetMaxDepotCapa();
            bool bIncrease = (nMaxDepotCapa <= nCurDepotUse + nChangeItemNums) ? true : false;
            if (bIncrease)
            {
                int nItemId = pEventMessage->GetGoodsId();
                vector<GameItem*>* pVctDepotItems = player->GetDepotItems();

                GameItem* pTargetItem = nullptr;
                for (GameItem* pGameItem : *pVctDepotItems)
                {
                    if (pGameItem->GetId() == nItemId)
                    {
                        pTargetItem = pGameItem;
                        break;
                    }
                }

                if (pTargetItem)
                {
                    int nCurItemNums = pTargetItem->GetCount();
                    pTargetItem->SetCount(nCurItemNums + nChangeItemNums);
                    pTargetItem->SetInPrice((pTargetItem->GetInPrice() * nCurItemNums / (nCurItemNums + nChangeItemNums)));
                }
                else
                {
                    GameItem* pGameItem = new GameItem();
                    pGameItem->SetId(nItemId);
                    pGameItem->SetInPrice(0);
                    pGameItem->SetCount(nChangeItemNums);
                    pVctDepotItems->push_back(pGameItem);
                }

                player->SetCurDepotUse(player->GetCurDepotUse() + nChangeItemNums);
            }
        }
        else
        {//仓库中货物数量减少
            // TODO

        }
    }
}
