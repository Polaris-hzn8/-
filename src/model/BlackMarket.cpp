///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "GameModel.h"
#include "BlackMarket.h"

BlackMarket::BlackMarket()
{
	m_id = 0;
	m_name = "";
}

BlackMarket::~BlackMarket()
{

}

/**
 * \brief ��ҹ�����Ʒ
 * \param nGoodsId
 * \param nGoodsNum
 * \return 0���׳ɹ� 1��Ʒ������ 2��Ʒ�������� 3��ҽ��� 4��Ҳֿ���������
 */
int BlackMarket::SellItem(int nGoodsId, int nSellItemNum)
{
	GameItem* pStoreItem = GetItemFromMarket(nGoodsId);
	// �����Ʒ�Ƿ����
	if (pStoreItem == nullptr)
		return 1;

	// �����Ʒʣ�������Ƿ��㹻
	int nStoreItemNum = pStoreItem->GetCount();
	if (nStoreItemNum < nSellItemNum)
		return 2;

	// �ж���ҵĽ�Ǯ�Ƿ��㹻
	GameRole* pGameRole = GameModel::getInstance()->getRole();
	int nBalance = pGameRole->GetCash();						// ���
	int nCost = nSellItemNum * (pStoreItem->GetOutPrice());		// ����
	if (nBalance < nCost)
		return 3;

	// �ж���ҵĲֿ�ռ�ʣ���С�Ƿ��㹻
	int nCurDepotUse = pGameRole->GetCurDepotUse();
	int	nMaxDepotCapa = pGameRole->GetMaxDepotCapa();
	if (nMaxDepotCapa < nCurDepotUse + nSellItemNum)
		return 4;

	// �޸��̵�����
	pStoreItem->SetCount(nStoreItemNum - nSellItemNum);			// ��Ʒ�����޸�

	// �޸��������
	pGameRole->SetCash(nBalance - nCost);						// �������޸�
	pGameRole->SetCurDepotUse(nCurDepotUse + nSellItemNum);

	///////////////////////////////////////////////////////////////////////////////////////////////////
	// �޸���Ҳֿ��е�����
	// �жϲֿ����Ƿ����и���Ʒ �������ֱ���������� �������´��������������������
	int nCid = pStoreItem->GetId();
	GameItem* pDepotItem = nullptr;
	vector<GameItem*>* pDepotItems = pGameRole->GetDepotItems();
	for (GameItem* pDepotItemTmp : *pDepotItems)
	{
		int nDid = pDepotItemTmp->GetId();
		if (nDid == nCid)
		{
			pDepotItem = pDepotItemTmp;
			break;
		}
	}

	if (!pDepotItem)
	{
		// ��Ʒ������
		pDepotItem = new GameItem();
		pDepotItem->SetId(pStoreItem->GetId());
		pDepotItem->SetName(pStoreItem->GetName());
		pDepotItem->SetInPrice(pStoreItem->GetOutPrice());
		pDepotItem->SetCount(nSellItemNum);
		pDepotItems->push_back(pDepotItem);
	}
	else
	{
		// ��Ʒ�Ѿ�����
		// ���Ӳֿ��Ѵ�����Ʒ����
		int nDepotItemNum = pDepotItem->GetCount();
		int nDepotItemNumNew = nDepotItemNum + nSellItemNum;
		pDepotItem->SetCount(nDepotItemNumNew);
		// ���¼������Ʒ�Ĺ������
		int InPrice = pDepotItem->GetInPrice();
		int nCost = nSellItemNum * (pStoreItem->GetOutPrice());
		int InPriceAvg = ((InPrice * nDepotItemNum) + nCost) / nDepotItemNumNew;
		pDepotItem->SetInPrice(InPriceAvg);
	}

	return 0;
}

GameItem* BlackMarket::GetItemFromMarket(int nGoodsId)
{
	GameItem* pStoreItem = nullptr;
	for (GameItem* pStoreItemTmp : m_itemList)
	{
		int nId = pStoreItemTmp->GetId();
		if (nId == nGoodsId)
		{
			pStoreItem = pStoreItemTmp;
			break;
		}
	}
	return pStoreItem;
}