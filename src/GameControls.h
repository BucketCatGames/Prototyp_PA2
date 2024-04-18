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

private:
	Player player;
};

