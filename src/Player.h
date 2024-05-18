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
	//Constructor and Destructor
	Player();
	~Player();

	//Variables
	float posX;
	float posY;
	float speed;
	float xVel;
	float yVel;

	//Health
	int currentHealth;
	int maxHealth;
	int amount;
	bool isAlive = true;

	//Vectors
	Vector2 PlayerPosVector;
	Vector2 PlayerVelVector;
	Vector2 MousePosVector;
	
	//Playerinitialization
	void InitPlayer();
	//void UpdatePlayer();
	void PlayerInput();
	void DrawPlayer();
	void SetMousePos();
	Bullets* ShootBullets();

	//PlayerHealth
	void DrawHealth();
	void AddHealth(int amount);
	void SubHealth(int amount);
	void SetHealth(int _health);
	void switchHealthState();

	//PlayerPosition
	float GetPlayerPosX();
	float GetPlayerPosY();
	
private:

	Texture2D texture;
	
	
};

