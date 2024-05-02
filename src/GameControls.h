#pragma once 
#include "Player.h"
#include <vector>

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

private:
	Player player;
	std::vector<Bullets*> bullets;
	Mouse mouse;
};

