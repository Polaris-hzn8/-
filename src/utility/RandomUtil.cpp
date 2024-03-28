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
 * \brief 从某个范围中获取随机数
 * \param min 范围的最小值
 * \param max 范围的最大值
 * \return 随机的数字
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
 * \brief 根据概率产生产生事件成功或者失败的结果
 * \param probability 1 ~ 100
 * \return 事件是否成功
 */
bool RandomUtil::getProbabilityResult(int probability)
{
	int randomNum = RandomUtil::getRandomInteger(0, 10000);
	if (probability * 100 >= randomNum)
		return true;
	else
		return false;
}
