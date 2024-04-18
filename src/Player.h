#pragma once
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include "Bullets.h"


class Player
{
public:
	Player();
	~Player();

	float posX;
	float posY;
	float speed;
	float xVel;
	float yVel;

	Vector2 playerPosVector;
//	std::vector<Bullets> bulletVector;

	void InitPlayer(Player& player);
	void UpdatePlayer(Player& player);
	void PlayerInput(Player& player);
	void DrawPlayer(Player& player);
	//void ShootBullets(Player& player, Bullets& bullets);
	

private:

	Texture2D texture;
	
};

