///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include <ctime>
#include <cstdlib>
#include "RandomUtil.h"

RandomUtil::RandomUtil()
{
	flag = false;
}

RandomUtil::~RandomUtil()
{
}

int RandomUtil::getRandomInteger(int min, int max)
{
	if (!flag) {
		srand((unsigned int)time(NULL));
		flag = true;
	}
	return rand() % (max - min) + max;
}

bool RandomUtil::getProbabilityResult(int probability)
{
	int num = RandomUtil::getRandomInteger(0, 10000);
	return probability * 100 >= num ? true : false;
}
