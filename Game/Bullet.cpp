#include "Bullet.h"
#include "Scene.h"

Bullet::Bullet(const std::string& path)
{
	SBullet = createPicture((path + "bubble@2x.png").c_str());
	setPictureSize(SBullet, widthBullet, heightBullet);
}

Bullet::~Bullet()
{
	destroyPicture(SBullet);
}

void Bullet::CreateBullet(int heroPosX, int heroPosY, int mousePosX, int mousePosY)
{
	Bullets.push_back(VBullet(heroPosX, heroPosY, mousePosX, mousePosY));
}

void Bullet::ValidateBullets()
{
	int count = Bullets.size();
	std::deque <VBullet>::iterator Iter;
	for (Iter = Bullets.begin(); Iter != Bullets.end();)
	{
		if (Iter->BeginY > Scene::heightScreen || Iter->BeginY < Scene::zero)
			Iter = Bullets.erase(Iter);
		else
			Iter++;
	}
}
