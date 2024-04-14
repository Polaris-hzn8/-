///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "GameRole.h"
#include "GameModel.h"

GameRole::GameRole()
{
	m_nCash = 2000;
	m_nDeposit = 0;
	m_nDebt = 5500;
	m_nHealth = 100;
	m_nFame = 100;

	m_nCurDepotUse = 0;
	m_nMaxDepotCapa = 30;
}

GameRole::~GameRole()
{
}

/**
 * �ж���Ʒ�Ƿ����
 * \param nGoodsId
 * \return
 */
bool GameRole::IsItemExist(int nGoodsId)
{
	GameItem* pDepotItem = GetItemFromDepot(nGoodsId);
	return (pDepotItem == nullptr) ? false : true;
}

/**
 * \brief ��ҳ�����Ʒ
 * \param nGoodsId		��ƷId
 * \param nSellItemNum	��Ʒ����
 * \param nCurOutPrice	��Ʒ��ǰ���ۼ۸�
 * \return 0���׳ɹ� 1�ֿ���Ʒ������ 2�ֿ���Ʒ��������
 */
int GameRole::SellItem(int nGoodsId, int nSellItemNum, int nCurOutPrice)
{
	// ���ֿ�����Ʒ�Ƿ����
	GameItem* pDepotItem = GetItemFromDepot(nGoodsId);
	if (pDepotItem == nullptr)
		return 1;

	// �����Ʒʣ�������Ƿ��㹻
	int nDepotItemNum = pDepotItem->GetCount();
	if (nDepotItemNum < nSellItemNum)
		return 2;

	// �޸�������
	GameRole* pGameRole = GameModel::getInstance()->getRole();
	int nBalance = pGameRole->GetCash();						// ���
	int nProfit = nSellItemNum * nCurOutPrice;					// �۳��ܽ��
	pGameRole->SetCash(nBalance + nProfit);						// �������޸�

	// �޸���Ҳֿ�ռ������
	int nCurDepotUse = pGameRole->GetCurDepotUse();
	int	nMaxDepotCapa = pGameRole->GetMaxDepotCapa();
	pGameRole->SetCurDepotUse(nCurDepotUse - nSellItemNum);

	// �޸Ĳֿ�洢��Ʒ����
	if (nDepotItemNum == nSellItemNum)
	{// ����Ʒȫ������
		vector<GameItem*>* pDepotItems = pGameRole->GetDepotItems();	// ��Ʒ����
		// pDepotItems->erase(pDepotItem);
		// erase������Ҫʹ�õ���������ɾ��
		for (auto itor = pDepotItems->begin(); itor != pDepotItems->end(); ++itor)
		{
			if ((*itor)->GetId() == pDepotItem->GetId())
			{
				pDepotItems->erase(itor);
				break;
			}
		}
	}
	else
	{// ����Ʒ����ʣ��
		pDepotItem->SetCount(nDepotItemNum - nSellItemNum);				// ��Ʒ�����޸�
	}
	return 0;
}

GameItem* GameRole::GetItemFromDepot(int nGoodsId)
{
	GameItem* pDepotItem = nullptr;
	for (GameItem* pDepotItemTmp : m_pDepotItems)
	{
		int nId = pDepotItemTmp->GetId();
		if (nId == nGoodsId)
		{
			pDepotItem = pDepotItemTmp;
			break;
		}
	}
	return pDepotItem;
}

