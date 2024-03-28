///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include <ctime>
#include <cstdlib>
#include "RandomUtil.h"

bool RandomUtil::flag = false;

RandomUtil::RandomUtil()
{
}

RandomUtil::~RandomUtil()
{
}

/**
 * \brief ��ĳ����Χ�л�ȡ�����
 * \param min ��Χ����Сֵ
 * \param max ��Χ�����ֵ
 * \return ���������
 */
int RandomUtil::getRandomInteger(int min, int max)
{
	if (!flag) {
		srand((unsigned int)time(NULL));
		flag = true;
	}
	return rand() % (max - min) + max;
}

/**
 * \brief ���ݸ��ʲ��������¼��ɹ�����ʧ�ܵĽ��
 * \param probability 1 ~ 100
 * \return �¼��Ƿ�ɹ�
 */
bool RandomUtil::getProbabilityResult(int probability)
{
	int randomNum = RandomUtil::getRandomInteger(0, 10000);
	if (probability * 100 >= randomNum)
		return true;
	else
		return false;
}
