#include <cstdlib>
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include "Player.h"

class Enemy {
protected:
	int enemyHealth;
	int enemySpeed;
	
	Vector2 enemyPos;
	Vector2 enemyMovement;

	bool isAlive;

	Texture2D enemyTexture;
public:
	void setEnemyHealth(int);
	int getEnemyHealth();

	void setEnemySpeed(int);
	int getEnemySpeed();

	void setEnemyPos(Vector2);
	Vector2 getEnemyPos();

	void setEnemyAliveState(bool);
	bool getEnemyAliveState();

	void setEnemyTecture(Texture2D);


	void movementToPlayer();  //Hier benötige ich von Gi noch getter uns Setter Funktionen für die playerPos

private:
	Player* player;
};