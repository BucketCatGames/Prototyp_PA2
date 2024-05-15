#pragma once
#include <cstdlib>
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include "Player.h"
#include <iostream>
#include <string>

class Enemy 
{
protected:
	int enemyHealth;
	int enemySpeed;
	
	Vector2 enemyPos;
	Vector2 enemyMovement;

	bool isAlive;

	Texture2D enemyTexture;
public:
	Enemy() {
		enemyPos.x = GetRandomValue(1,GetScreenWidth());
		enemyPos.y = GetRandomValue(1,GetScreenHeight());
		this->enemyTexture = LoadTexture("assets/graphics/Enemy.png");
		this->isAlive = true;
		this->enemyHealth = 100;
		this->enemySpeed = 5;
	}

	void setEnemyHealth(int);
	int getEnemyHealth();

	void setEnemySpeed(int);
	int getEnemySpeed();

	void setEnemyPos(Vector2);
	Vector2 getEnemyPos();

	void setEnemyAliveState(bool);
	bool getEnemyAliveState();

	void setEnemyTexture(Texture2D);

	void movementToPlayer(Player& player);  //Hier benötige ich von Gi noch getter uns Setter Funktionen für die playerPos

	void drawEnemy();

private:
};