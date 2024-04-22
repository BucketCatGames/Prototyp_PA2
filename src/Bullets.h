#pragma	once
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include "Mouse.h"

/*
struct Bullets
{
	Vector2 bulletSpawnVector;
	Vector2 shootDirVector;
	Texture2D textureBullet;
};

void DrawBullet(Bullets& bullet);
void ShootBullet(Player& player, Mouse& mouse, Bullets& bullet);
void UpdateBullet(Bullets& bullet);
void InitBullet(Player& player, Mouse& mouse, Bullets& bullet);
void BulletTexture(Bullets& bullet);*/
class Bullets
{
public:
	Bullets(Vector2 bulletSpawnVector, Vector2 mousePos, Texture2D textureBullet, float speed, float bulletTimer, float bulletTimerMax);
	float bulletPosX;
	float bulletPosY;
	float bulletTimer;
	float bulletTimerMax;
	
	Vector2 bulletDirVector;
	void UpdateBullet();
	void DrawBullet();
	Vector2 GetBulletDir(Vector2 mousePos);
	bool active;
	bool drawable = false;
	Texture2D textureBullet;

private:
	int speed;
	int t;

};