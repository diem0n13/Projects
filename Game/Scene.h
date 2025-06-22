#pragma once
#include "GameFrame.h"
#include <string>
#include <deque>
#include "RectangleN.h"
#include <ctime>
#include "Enemy.h"

class Scene
{
private:

public:
	static const int widthScreen = 600, heightScreen = 800, halfHeightScreen = 400, width = 80, height = 20, 
		zero = 0, single = 1, maxYStep = 100, minStep = 20, stepBullet = 2, stepEnemy = 5, offSetEnemyY = 50, offSetEnemyX = 50,
		stepTimer = 2000;
	Picture* BackGround;
	Picture* SPlatporm;
	Enemy* CEnemy;
	std::deque<RectangleN> Platforms;

	Scene(const std::string& path);
	~Scene();
	void CreatePlatforms(const int& curentPosX, const int& curentPosY, unsigned int& timer);
	void FillPlatforms(const int& curentPosX, const int& curentPosY, unsigned int& timer);
	void MoveScene(const int& step,const unsigned int& timer);
	int GetRandom(const int& step);
	void ResetPlatforms(const int& limit, const int& curentPosY);
};
