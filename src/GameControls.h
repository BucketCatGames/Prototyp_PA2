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
	void DrawDeath();
	void Update();
	void HandleInput();
	void InitFunctions();
	void DeleteBullets();
	void DeleteBulletsTimer();
	void BulletsStopMoving();
	void Death();
	void DeleteAllBullets();

private:
	Player player;
	std::vector<Bullets*> bullets;
	Mouse mouse;
};

