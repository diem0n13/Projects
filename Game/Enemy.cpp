#include "Enemy.h"
#include "Scene.h"

Enemy::Enemy(const std::string& path)
{
	EnemyLO = createPicture((path + "ooga-left-odskok@2x.png").c_str());
	setPictureSize(EnemyLO, widthEnemy, heightEnemy);
	EnemyL = createPicture((path + "ooga-left@2x.png").c_str());
	setPictureSize(EnemyL, widthEnemy, heightEnemy);
	EnemyPada = createPicture((path + "ooga-pada@2x.png").c_str());
	setPictureSize(EnemyPada, widthEnemy, heightEnemy);
	EnemyPuca = createPicture((path + "ooga-puca@2x.png").c_str());
	setPictureSize(EnemyPuca, widthEnemy, heightEnemy);
	EnemyPD = createPicture((path + "ooga-puca-dolje@2x.png").c_str());
	setPictureSize(EnemyPD, widthEnemy, heightEnemy);
	EnemyPO = createPicture((path + "ooga-puca-odskok@2x.png").c_str());
	setPictureSize(EnemyPO, widthEnemy, heightEnemy);
	EnemyR = createPicture((path + "ooga-right@2x.png").c_str());
	setPictureSize(EnemyR, widthEnemy, heightEnemy);
	EnemyRO = createPicture((path + "ooga-right-odskok@2x.png").c_str());
	setPictureSize(EnemyRO, widthEnemy, heightEnemy);
}

Enemy::~Enemy()
{
	destroyPicture(EnemyLO);
	destroyPicture(EnemyL);
	destroyPicture(EnemyRO);
	destroyPicture(EnemyR);
	destroyPicture(EnemyPO);
	destroyPicture(EnemyPD);
	destroyPicture(EnemyPuca);
	destroyPicture(EnemyPada);
	//delete
}
