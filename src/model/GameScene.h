///****************************************************************************
/// @Author		: Polaris-hzn8
/// @CreateTime	: 2024-03-26 22:57
/// @Mail		: 3453851623@qq.com
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
	void SetId(int id) { m_id = id; }
	string GetName() { return m_name; }
	void setName(string name) { m_name = name; }
protected:
	
private:
	int		m_id;		// ³¡¾°id
	string	m_name;		// ³¡¾°Ãû³Æ
};

