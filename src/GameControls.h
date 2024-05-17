#pragma once 
#include "Player.h"
#include <vector>
#include "Enemy.h"
#include "PressurePlate.h"
#include "MovableObject.h"

class GameInit
{
public:
	GameInit();
	~GameInit();

	bool isPlayable;

	void Draw();
	void Update();
	void HandleInput();
	void InitFunctions();
	void DeleteBullets();
	void DeleteBulletsTimer();
	void BulletsStopMoving();
	void DeleteAllBullets();
	void CollectBullets();
	void UpdateTimer();
	void UpdateBullets();
	void EnemyBulletCollision();
	void SpawnEnemy();
	void UpdateEnemy();
	void PlayerMovableObjectCollision();
	void MovableObjectPressurePlateCollision();

private:
	int maxEnemyCount = 3;
	Player player;
	std::vector<Enemy> enemy;
	std::vector<Bullets*> bullets;
	Mouse mouse;
	PressurePlate pressurePlate;
	MovableObject movableObject;
};

