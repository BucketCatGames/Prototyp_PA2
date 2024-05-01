#pragma	once
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include "Mouse.h"


class Bullets
{
public:
	Bullets(Vector2 bulletSpawnVector, Vector2 mousePos, Texture2D textureBullet, float speed, float bulletTimer, float bulletTimerMax, 
		float bulletTimerStop, int bulletCost, float spawnTimer);
	~Bullets();
	float bulletPosX;
	float bulletPosY;
	float bulletTimer;
	float bulletTimerMax;
	float bulletTimerStop;
	float spawnTimer;
	int speed;
	int bulletCost;

	Vector2 bulletDirVector;
	void UpdateBullet();
	void DrawBullet();

	Vector2 GetBulletDir(Vector2 mousePos);
	bool active;
	bool drawable = false;
	Texture2D textureBullet;

private:
	
	int t;

};