#pragma once
#include "RectangleN.h"


class VBullet
{
public:
	//static const int stepBullet = 2;
	//RectangleN* Bullet;
	float VectorX = 0.0f;
	float VectorY = 0.0f;
	int BeginX = 0;
	int BeginY = 0;
	int stepBullet = 2;
	
	VBullet(int heroPosX, int heroPosY, int mousePosX, int mousePosY);

	void Normalize(const int& x, const int& y);
	int GetCoordinateX();
	int GetCoordinateY();
};

