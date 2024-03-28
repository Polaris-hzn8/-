///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-03-27 22:57
/// @Mail		: 3453851623@qq.com
///****************************************************************************

#pragma once

class RandomUtil
{
public:
	RandomUtil();
	~RandomUtil();
	static int getRandomInteger(int min, int max);		//随机生成数字
	static bool getProbabilityResult(int probability);	//某事件是否随机成功
private:
	static bool flag;		//是否产生过随机种子
};
