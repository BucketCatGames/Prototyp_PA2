#pragma	once
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include "Player.h"
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
	Bullets(Vector2 bulletSpawnVector, Vector2 shootDirVector, Texture2D textureBullet, int speed);
	void UpdateBullet(Bullets& bullet);
	void DrawBullet();

	bool active;
	bool drawable = false;

private:

	Vector2 bulletSpawnVector;
	Vector2 shootDirVector;
	Texture2D textureBullet;
	int speed;
	int t;
	float bulletTimer;
	float bulletTimerMax;
};