#include "VBullet.h"
#include "cmath"
#include "Scene.h"

VBullet::VBullet(int heroPosX, int heroPosY, int mousePosX, int mousePosY)
{
	int vectX = mousePosX - heroPosX;
	int vectY = mousePosY - heroPosY;
	BeginX = heroPosX;
	BeginY = heroPosY;
	if (vectX != 0 && vectY != 0)
		Normalize(vectX, vectY);
}

void VBullet::Normalize(const int& x, const int& y)
{
	float length = std::sqrt(x * x + y * y);
	if (length != 0.0f) {
		VectorX = x / length;
		VectorY = y / length;
	}
}
int VBullet::GetCoordinateX()
{
	if (Scene::zero > BeginX)
		BeginX = Scene::widthScreen - Scene::single;
	if (Scene::widthScreen < BeginX)
		BeginX = Scene::zero + Scene::single;
	float buf = VectorX * Scene::stepBullet + BeginX;
	BeginX = round(buf);
	return BeginX;
}
int VBullet::GetCoordinateY()
{
	float buf = VectorY * Scene::stepBullet + BeginY;
	BeginY = round(buf);
	return BeginY;
}