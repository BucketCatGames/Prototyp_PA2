#pragma once
#include <cstdlib>
#include <iostream>
#include <raylib.h>
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

	Vector2 PlayerPosVector;
	Vector2 PlayerVelVector;
	Vector2 MousePosVector;
	
	//std::vector<Bullets> bulletVector;

	void InitPlayer();
	void UpdatePlayer();
	void PlayerInput();
	void DrawPlayer();
	void SetMousePos();
	Bullets* ShootBullets();

	
private:

	Texture2D texture;
	
	
};

