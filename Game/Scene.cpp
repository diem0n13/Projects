#include "Scene.h"
#include <cstdlib>
#include <ctime>

Scene::Scene(const std::string& path)
{
	BackGround = createPicture((path + "hop-bck@2x.png").c_str());
	setPictureSize(BackGround, widthScreen, heightScreen);

	SPlatporm = createPicture((path + "hop-bottom@2x.png").c_str());
	setPictureSize(SPlatporm, width, height);

	CEnemy = new Enemy(path);
}
Scene::~Scene()
{
	destroyPicture(BackGround);
	destroyPicture(SPlatporm);
	delete CEnemy;
}

void Scene::CreatePlatforms(const int& curentPosX, const int& curentPosY, unsigned int& timer)
{
	int x = curentPosX;
	int y = curentPosY;
	Platforms.push_back(RectangleN(x, y, curentPosX + width, curentPosY + height, timer * stepTimer));
	FillPlatforms(-halfHeightScreen, curentPosY, timer);
}

void Scene::FillPlatforms(const int& limit, const int& curentPosY, unsigned int& timer)
{
	std::srand(std::time(0));
	int currentY = curentPosY, step, nextY, nextX, numEnemy = 0, i = -1;
	bool created = false;
	while (currentY > limit)
	{
		step = GetRandom(maxYStep);
		nextY = currentY - step;
		if (nextY < limit)
			break;
		nextX = GetRandom(widthScreen - width);
		if (currentY < Scene::zero && !created)
		{
			numEnemy = GetRandom(stepEnemy);
			created = true;
			i = 1;
		}
		if (created)
		{
			if (i == numEnemy)
			{
				CEnemy->Enemies.push_back(RectangleN(nextX, nextY - offSetEnemyY, nextX + offSetEnemyX, nextY));
				created = false;
				i = -1;
			}
			else
			{
				i++;
			}
		}
		Platforms.push_back(RectangleN(nextX, nextY, nextX + width, nextY + height, timer + stepTimer));
		currentY = nextY;
	}
}

inline int Scene::GetRandom(const int& step)
{
	return std::rand() % step - single;
}

void Scene::ResetPlatforms(const int& curentPosX, const int& curentPosY)
{
	Platforms.clear();
	CEnemy->Enemies.clear();
}
void Scene::MoveScene(const int& step, const unsigned int& timer)
{
	unsigned int buffTimer = timer;
	int count = Platforms.size();
	std::deque <RectangleN>::iterator rectIter;
	for (rectIter = Platforms.begin(); rectIter != Platforms.end();)
	{
		rectIter->SetRectangle(step);
		if (rectIter->LeftTopY < minStep && rectIter->LeftTopY>zero)
		{
			rectIter->PTimer = timer + stepTimer;
		}
		if (rectIter->LeftTopY > heightScreen)
		{
			rectIter = Platforms.erase(rectIter);
		}
		else
		{
			rectIter++;
		}
	}
	count = CEnemy->Enemies.size();
	for (rectIter = CEnemy->Enemies.begin(); rectIter != CEnemy->Enemies.end();)
	{
		rectIter->SetRectangle(step);
		if (rectIter->LeftTopY > heightScreen || !rectIter->IsActivated)
		{
			rectIter = CEnemy->Enemies.erase(rectIter);
		}
		else
		{
			rectIter++;
		}
	}

	count = Platforms.back().LeftTopY;
	if (count >= zero)
		FillPlatforms(-halfHeightScreen, count, buffTimer);
}