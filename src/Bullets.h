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


struct Bullets
{
	float bulletSpeed;

	Vector2 bulletSpawnVector;
	Vector2 shootDirVector;
	Texture2D textureBullet;
};

void BulletTexture(Bullets& bullet);
void InitBullet(Player& player, Mouse& mouse, Bullets& bullet);
void UpdateBullet(Bullets& bullet);
void ShootBullet(Player& player, Mouse& mouse, Bullets& bullet);
void DrawBullet(Bullets& bullet);