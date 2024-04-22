#pragma once 
#include "Player.h"
#include <vector>

class GameInit
{
public:
	GameInit();
	~GameInit();

	void Draw();
	void Update();
	void HandleInput();
	void InitFunctions();
	void DeleteBullets();
	void DeleteBulletsTimer();
private:
	Player player;
	std::vector<Bullets*> bullets;
	Mouse mouse;
};

