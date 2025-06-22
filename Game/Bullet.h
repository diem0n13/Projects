#pragma once
#include "GameFrame.h"
#include <string>
#include <deque>
#include "RectangleN.h"
#include"VBullet.h"

class Bullet
{
public:
	Picture* SBullet;
	std::deque<VBullet> Bullets;
	const int widthBullet = 16, heightBullet = 16;

	Bullet(const std::string& path);
	~Bullet();
	void CreateBullet(int heroPosX, int heroPosY, int mousePosX, int mousePosY);
	void ValidateBullets();
};

