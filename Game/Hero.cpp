#include "Hero.h"


Hero::Hero(const std::string& path, int x, int y)
{
	HeroLeft = createPicture((path + "jungle-left@2x.png").c_str());
	setPictureSize(HeroLeft, width, height);
	HeroLeftODSKOK = createPicture((path + "jungle-left-odskok@2x.png").c_str());
	setPictureSize(HeroLeftODSKOK, width, height);
	HeroNjushka = createPicture((path + "jungle-njuska@2x.png").c_str());
	setPictureSize(HeroNjushka, width, height);
	HeroPuka = createPicture((path + "jungle-puca@2x.png").c_str());
	setPictureSize(HeroPuka, width, height);
	HeroPukaODSKOK = createPicture((path + "jungle-puca-odskok@2x.png").c_str());
	setPictureSize(HeroPukaODSKOK, width, height);
	HeroRight = createPicture((path + "jungle-right@2x.png").c_str());
	setPictureSize(HeroRight, width, height);
	HeroRightODSKOK = createPicture((path + "jungle-right-odskok@2x.png").c_str());
	setPictureSize(HeroRightODSKOK, width, height);
	HeroNose = createPicture((path + "lik-njuska@2x.png").c_str());
	//setSpriteSize(HeroNose, width, height);

	Position = new RectangleH(x, y, x + width, y + height);
}

Hero::~Hero()
{
	destroyPicture(HeroLeft);
	destroyPicture(HeroLeftODSKOK);
	destroyPicture(HeroNjushka);
	destroyPicture(HeroPuka);
	destroyPicture(HeroPukaODSKOK);
	destroyPicture(HeroRight);
	destroyPicture(HeroRightODSKOK);
	delete Position;
}

void Hero::SetPositionY(bool isUp, const int& step)
{
	Position->SetPositionY(isUp, step);
}

void Hero::SetPositionX(bool toLeft, const int& step)
{
	Position->SetPositionX(toLeft, step);
}

void Hero::ResetPosition(const int& x, const int& y)
{
	delete Position;
	Position = new RectangleH(x, y, x + width, y + height);
}