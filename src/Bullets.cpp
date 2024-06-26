#pragma once
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include "Bullets.h"
#include "Player.h"
#include "Mouse.h"


Bullets::Bullets(Vector2 bulletSpawnVector, Vector2 mousePos, Texture2D textureBullet, float speed, float bulletTimer, float bulletTimerMax,
	float bulletTimerStop, int bulletCost, float spawnTimer)
{
	this->bulletPosX = bulletSpawnVector.x;
	this->bulletPosY = bulletSpawnVector.y;
	this->bulletDirVector = Vector2Normalize(GetBulletDir(mousePos));
	this->textureBullet = textureBullet;
	this->speed = speed;
	this->active = true;
	this->bulletTimer = bulletTimer;
	this->bulletTimerMax = bulletTimerMax;
	this->bulletTimerStop = bulletTimerStop;
	this->bulletCost = bulletCost;
	this->spawnTimer = spawnTimer;
}
Bullets::~Bullets()
{
	UnloadTexture(textureBullet);
}

void Bullets::DrawBullet()
{
	DrawTexture(textureBullet, bulletPosX, bulletPosY, RAYWHITE);
}
Vector2 Bullets::GetBulletDir(Vector2 mousePos)
{
	Vector2 bulletSpawnVector = { bulletPosX, bulletPosY };
	Vector2 dir = Vector2Subtract( mousePos, bulletSpawnVector);
	return dir;
}

void Bullets::UpdateBullet()
{
	bulletPosX += bulletDirVector.x * speed; //X Achse
	bulletPosY += bulletDirVector.y * speed; //Y Achse

	if (bulletTimer >= bulletTimerStop)
	{
		speed = 0;
	}
	else
	{
		speed = 5;
	}
}
