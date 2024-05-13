#pragma once 
#include "Player.h"
#include <vector>
#include "Enemy.h"

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

private:
	Player player;
	Enemy enemy;
	std::vector<Bullets*> bullets;
	Mouse mouse;
};

