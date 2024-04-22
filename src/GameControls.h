#pragma once 
#include "Player.h"

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
private:
	Player player;
	Bullets bullets;
	Mouse mouse;
};

