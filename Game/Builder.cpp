#include "Builder.h"
#include <windows.h>

Builder::Builder()
{
	//int curTimer = getTickCount();
	//curTimer / koef;
	//step = 2;//curTimer / koef;

	std::string path = InitPath();
	scene = new Scene(path);
	hero = new Hero(path, beginX, beginY);
	bullets = new Bullet(path);
	currentSprite = hero->HeroLeft;
	currentPosY = hero->Position->getRightBottomY();
	globalSpeed = koefDefault;
}

Builder::~Builder()
{
	delete scene;
	delete hero;
	delete bullets;
}

string Builder::InitPath()
{
	using std::string;
	char fullPath[MAX_PATH];
	DWORD length = GetModuleFileNameA(NULL, fullPath, MAX_PATH);
	size_t pos = string(fullPath).find_last_of("/\\");
	return string(fullPath, pos).append("\\data\\");
}

void  Builder::BuildScene(unsigned int& timer)
{
	drawPicture(scene->BackGround, Scene::zero, Scene::zero);
	if (IsNeedChange)
	{
		scene->CreatePlatforms(beginX, beginY + offsetPlatform, timer);
		IsNeedChange = false;
	}
	int count = (int)scene->Platforms.size();
	RectangleN* rect = nullptr;
	for (int i = 0; i < count; i++)
	{
		rect = &scene->Platforms[i];
		////const RectangleN& rect = scene->Platforms[i];
		//int diffTimer = timer - rect->PTimer;
		//if (rect->LeftTopY > Scene::minStep && diffTimer > platformTimer)
		//	rect->IsActivated = false;
		//if (rect->IsActivated)
		{
			drawPicture(scene->SPlatporm, rect->LeftTopX, rect->LeftTopY);
		}
	}
}

void Builder::BuildHero()
{
	//drawSprite(scene->SPlatporm, 0, 662);
	//drawSprite(currentSprite, 0, 0);
	//drawSprite(bullets->SBullet, 0,28);//side 60
	//drawSprite(enemy->EnemyL, 0, 650);
	//Score = 's';

	unsigned int curTimer = getTickCount();
	BuildScene(curTimer);

	if (hero->Position->getRightBottomY() >= Scene::heightScreen || IsCrossedEnemy)
	{
		Reset();
	}

	if (JumpOrFall == Direction::UP)
	{
		if (hero->Position->getRightBottomY() >= currentPosY - maxJump)
		{
			hero->SetPositionY(true, stepJump * globalSpeed);
		}
		else
		{
			JumpOrFall = Direction::DOWN;
			hero->SetPositionY(false, stepJump * globalSpeed);
		}
	}
	else
	{
		if (LandingOnPlatform() && hero->Position->getRightBottomY() >= currentPosY)
		{
			JumpOrFall = Direction::UP;
			hero->SetPositionY(true, stepJump * globalSpeed);
			IsSteelInRect = false;
		}
		hero->SetPositionY(false, stepJump * globalSpeed);
	}

	if (IsMove)
	{
		switch (direction)
		{
		case FRKey::LEFT: hero->SetPositionX(true, stepMove); break;
		case FRKey::RIGHT: hero->SetPositionX(false, stepMove); break;
		}
	}

	if (Scene::zero > hero->Position->getRightBottomX())
		hero->SetPositionX(false, Scene::widthScreen + Hero::width - Scene::single);
	if (Scene::widthScreen < hero->Position->getLeftTopX())
		hero->SetPositionX(true, Scene::widthScreen + Hero::width + Scene::single);

	if (hero->Position->getRightBottomY() <= Scene::halfHeightScreen)
	{
		scene->MoveScene(stepMove, curTimer);
		currentPosY += stepMove;
	}

	if (IsAvtoShooting)
	{
		unsigned int diff = curTimer - AvtoShootTimer;
		if (diff > bulletTimer)
			IsAvtoShooting = false;
	}

	bullets->ValidateBullets();
	int bulletCount = (int)bullets->Bullets.size();
	int enemyCount = (int)scene->CEnemy->Enemies.size();
	int i, j;
	VBullet* bullet = nullptr;
	RectangleN* enemy = nullptr;
	
	for (i = 0; i < bulletCount; i++)
	{
		bullet = &bullets->Bullets[i];
		drawPicture(bullets->SBullet, bullet->GetCoordinateX(), bullet->GetCoordinateY());
		for (j = 0; j < enemyCount; j++)
		{
			enemy = &scene->CEnemy->Enemies[j];
			if (InsideRectangle(bullet->BeginX, bullet->BeginY, enemy))
			{
				enemy->IsActivated = false;
			}
		}
	}

	RectangleH* hPos = hero->Position;
	int hltx = hPos->getLeftTopX();
	int hrbx = hPos->getRightBottomX();
	int hrby = hPos->getRightBottomY();
	int hlty = hPos->getLeftTopY();
	
	//int hltx = hPos->getLeftTopX();
	//int hltx = hPos->getLeftTopX();
	int sideEnemy = Scene::widthScreen * koefHalf;
	int positionX = hltx + (hrbx - hltx) * koefHalf;
	for (i = 0; i < enemyCount; i++)
	{
		enemy = &scene->CEnemy->Enemies[i];
		//const RectangleN& rect = scene->CEnemy->Enemies[i];
		if (enemy->LeftTopY > Scene::minStep && IsHitEnemy(positionX, hrby, enemy->LeftTopX,
			enemy->LeftTopY, enemy->RightBottomX, enemy->LeftTopY))
		{
			enemy->IsActivated = false;
		}
		if (enemy->IsActivated && enemy->RightBottomY > -Scene::minStep)
		{
			if (enemy->LeftTopY < Scene::minStep && enemy->LeftTopY > Scene::zero && enemy->IsShootActivated)
			{
				enemy->IsShootActivated;
				AvtoShootTimer = curTimer;
				BeetweenShootsTimer = curTimer;
				IsAvtoShooting = true;
			}

			if (sideEnemy > enemy->LeftTopX)
				drawPicture(scene->CEnemy->EnemyR, enemy->LeftTopX, enemy->LeftTopY);
			else
				drawPicture(scene->CEnemy->EnemyL, enemy->LeftTopX, enemy->LeftTopY);

			if (InsideRectangle(hrbx, hrby, enemy) ||
				InsideRectangle(hltx, hrby, enemy) ||
				InsideRectangle(hrbx, hlty, enemy) ||
				InsideRectangle(hltx, hlty, enemy))
			{
				IsCrossedEnemy = true;
			}
		}
	}

	Sleep(speedTimer);
	if (!IsCrossedEnemy)
		drawPicture(currentSprite, hero->Position->getLeftTopX(), hero->Position->getLeftTopY());
}
void Builder::Scores()
{
	unsigned int curTimer = getTickCount();
	int dif = curTimer;
	//char buffer[20];
	//sprintf_s(Score, sizeof(Score), "%d", dif);
	//char* ch = new char[50] {'H', 't', '\0'};
	//Score = 's';
	//int leng = 50;
		//char* ch = new char[leng];
		//strcpy_s(ch, leng, "Score          Distance          ");
	//Scores();
	//Score = (char)direction;
	//Score[1] = '\0';
}

void Builder::SetCurrentSprite(FRKey& key)
{
	switch (key)
	{
	case FRKey::LEFT:
		currentSprite = hero->HeroLeft;
		direction = key;
		break;
		//return inPlatform ? HeroLeftODSKOK : HeroLeft;
	case FRKey::RIGHT:
		currentSprite = hero->HeroRight;
		direction = key;
		break;
		//return inPlatform ? HeroRightODSKOK : HeroRight;
	case FRKey::UP:
		break;
	case FRKey::COUNT:
		break;
	}
}

bool Builder::LandingOnPlatform()
{
	int count = (int)scene->Platforms.size();
	int y = hero->Position->getRightBottomY();
	int lx = hero->Position->getLeftTopX() + Hero::border;
	int rx = hero->Position->getRightBottomX() - Hero::border;
	RectangleN* rect = nullptr;
	for (int i = 0; i < count; i++)
	{
		rect = &scene->Platforms[i];
		if (InsideRectangle(lx, y, rect) || InsideRectangle(rx, y, rect))
		{
			if (JumpOrFall == Direction::DOWN && !IsSteelInRect)
			{
				IsSteelInRect = true;
				if (rect->IsJumped)
				{
					if (koefMax > globalSpeed)
						globalSpeed *= koefMaximaze;
					else
						globalSpeed = koefMax;
				}
				else
				{
					if (globalSpeed > koefHalf)
						globalSpeed *= koefMinimaze;
					else
						globalSpeed = koefHalf;
					rect->IsJumped = true;
				}
			}
			currentPosY = rect->LeftTopY + offsetHero;
			return true;
		}
	}
	return false;
}

void Builder::Reset()
{
	IsPushed = false;
	IsMove = false;
	IsCreatedBullet = false;
	IsCrossedEnemy = false;
	IsAvtoShooting = false;
	unsigned int AvtoShootTimer;
	IsNeedChange = true;
	globalSpeed = koefDefault;
	direction = FRKey::LEFT;
	JumpOrFall = Direction::UP;
	currentPosY = hero->Position->getRightBottomY();

	hero->ResetPosition(beginX, beginY);
	scene->ResetPlatforms(beginX, beginY + offsetPlatform);
	bullets->Bullets.clear();
}

void Builder::DrawBullets(FRMouseButton button, bool isReleased)
{
	if (button == FRMouseButton::LEFT && !isReleased)
		IsPushed = true;
	else
	{
		IsPushed = false;
		IsCreatedBullet = false;
	}
}

void Builder::SetBulletCoordinate(int& x, int& y)
{
	unsigned int curTimer = getTickCount();
	if (IsPushed && !IsCreatedBullet || (IsAvtoShooting && curTimer - BeetweenShootsTimer > stepShoots))
	{
		BeetweenShootsTimer = curTimer;
		bullets->CreateBullet(hero->Position->getLeftTopX(), hero->Position->getLeftTopY(), x, y);
		IsCreatedBullet = true;
	}
}

bool Builder::IsHitEnemy(const int& hx, const int& hy, const int& ex1, const int& ey1, const int& ex2, const int& ey2)
{
	int diff = ey2 - hy;
	return (hx >= ex1 && hx < ex2) && (diff >= 0 && diff <= stepJump);
}

bool Builder::InsideRectangle(int& x, int& y, RectangleN* rect)
{
	return x >= rect->LeftTopX && x <= rect->RightBottomX && y >= rect->LeftTopY && y <= rect->RightBottomY;
}
