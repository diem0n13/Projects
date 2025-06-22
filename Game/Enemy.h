#pragma once
#include "GameFrame.h"
#include <string>
#include <deque>
#include "RectangleN.h"

class Enemy
{
public:
	Picture* EnemyLO;
	Picture* EnemyL;
	Picture* EnemyRO;
	Picture* EnemyR;
	Picture* EnemyPada;
	Picture* EnemyPuca;
	Picture* EnemyPO;
	Picture* EnemyPD;

	const int widthEnemy = 50, heightEnemy = 62;

	std::deque<RectangleN> Enemies;
	//const int

	Enemy(const std::string& path);
	~Enemy();
};

