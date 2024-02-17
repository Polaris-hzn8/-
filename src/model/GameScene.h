///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#pragma once

#include <string>
using namespace std;

class GameScene
{
public:
	GameScene();
	~GameScene();

	int GetId() { return m_id; }
	void SetId(int val) { m_id = val; }
	string GetSceneName() { return m_sceneName; }
	void setSceneName(string val) { m_sceneName = val; }
protected:
	
private:
	int m_id;
	string m_sceneName;
};

