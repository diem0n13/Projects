#pragma once
#include"Scene.h"
#include"Hero.h"
#include<string>
#include "GameFrame.h"
#include "RectangleN.h"
#include "Scene.h"
#include "Hero.h"
#include "Bullet.h"
#include "Enemy.h"
#include"VBullet.h"
//#include"list"

using std::string;
enum Direction{UP,DOWN};
class Builder
{

private:
	Picture* currentSprite;
	Scene* scene;
	Hero* hero;
	Bullet* bullets;
	const int beginX = 175, beginY = 700, maxJump = 200, offsetPlatform = 50, stepJump = 2, stepMove = 1, 
		offsetHero = 12, speedTimer = 10, platformTimer = 2500, bulletTimer = 20000, stepShoots = 500;

	const float koefHalf = 0.5f, koefMinimaze = 0.95f, koefMaximaze = 1.15f, koefMax = 3.0f, 
		deltaTime = koefDefault / 60.0f, koefDefault = 1.0f, eps = 0.01;

	float globalSpeed;

	FRKey direction = FRKey::LEFT;
	Direction JumpOrFall = Direction::UP;
	int currentPosY;
	bool IsSteelInRect = false;
	bool IsPushed = false;
	bool IsNeedChange = true;
	bool IsCreatedBullet = false;
	bool IsCrossedEnemy = false;
	bool IsAvtoShooting = false;
	unsigned int AvtoShootTimer;
	unsigned int BeetweenShootsTimer;

public:
	char* Score;
	bool IsMove = false;
	
	//scale

	Builder();
	~Builder();
	void BuildScene(unsigned int& timer);
	void BuildHero();
	string InitPath();
	void Scores();
	void DrawBullets(FRMouseButton button, bool isReleased);
	void SetBulletCoordinate( int& x, int& y);
	void SetCurrentSprite(FRKey& key);
	bool IsHitEnemy(const int& hx, const int& hy, const int& ex1, const int& ey1, const int& ex2, const int& ey2);
	bool LandingOnPlatform();
	bool InsideRectangle(int& x, int& y, RectangleN* rect);
	void Reset();
};

