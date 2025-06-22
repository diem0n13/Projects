#pragma once
#include "GameFrame.h"
#include "RectangleH.h"

#include <string>
class Hero
{
private:
	//const int width = 60, height = 62;

public:
	static const int width = 60, height = 62, border = 16;

	Picture* HeroLeft;
	Picture* HeroLeftODSKOK;
	Picture* HeroNjushka;
	Picture* HeroPuka;
	Picture* HeroPukaODSKOK;
	Picture* HeroRight;
	Picture* HeroRightODSKOK;
	Picture* HeroNose;

	RectangleH* Position;
	
	Hero(const std::string& path, int x, int y);
	~Hero();
	void SetPositionY(bool isUp, const int& step);
	void SetPositionX(bool toLeft, const int& step);
	void ResetPosition(const int& x, const int& y);
	//void Rotate(const int& x, const int& y);
};

