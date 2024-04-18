#pragma once
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include "Bullets.h"


//void BulletTexture(Bullets& bullet)
//{
//	bullet.textureBullet = LoadTexture("assets/graphics/Probe-Schmetterling.png");
//}
//
//void InitBullet(Player& player, Mouse& mouse, Bullets& bullet)
//{
//	Vector2 shootDirVector;
//	shootDirVector = Vector2Subtract(mouse.mousePosVector, player.playerPosVector);
//	shootDirVector = bullet.shootDirVector;
//
//
//	bullet.bulletSpawnVector = player.playerPosVector;
//	bullet.shootDirVector = Vector2Subtract(mouse.mousePosVector, player.playerPosVector);
//	bullet.shootDirVector = Vector2Normalize(bullet.shootDirVector);
//	bullet.shootDirVector = Vector2Scale(bullet.shootDirVector, 10);
//
//}
//void DrawBullet(Bullets& bullet)
//{
//	DrawTexture(bullet.textureBullet, bullet.bulletSpawnVector.x, bullet.bulletSpawnVector.y, RAYWHITE);
//}
//void UpdateBullet(Bullets& bullet)
//{
//	bullet.bulletSpawnVector = Vector2Add(bullet.bulletSpawnVector, bullet.shootDirVector);
//	DrawTextureV(bullet.textureBullet, bullet.bulletSpawnVector, RAYWHITE);
//	//DrawTexture(bullet.textureBullet, 100, 100, RAYWHITE);
//}
//
//void ShootBullet(Player& player, Mouse& mouse, Bullets& bullet)
//{
//	InitBullet(player, mouse, bullet);
//
//}
Bullets::Bullets(Vector2 bulletSpawnVector, Vector2 shootDirVector, Texture2D textureBullet, int speed)
{
	Player player = Player();
	this->t = 2.0f;
	this->bulletSpawnVector = player.playerPosVector;
	this->shootDirVector = shootDirVector;
	this->textureBullet = LoadTexture("assets/graphics/Probe-Schmetterling.png");
	this->speed = speed;
	this->active = true;
	this->bulletTimer = t;
	this->bulletTimerMax = t;
}
void Bullets::DrawBullet()
{
	if (active)
	{
		DrawTexture(textureBullet, 100, 100, RAYWHITE);
	}
}

void Bullets::UpdateBullet(Bullets& bullet)
{
	//bulletSpawnVector = Vector2Add(bulletSpawnVector, shootDirVector);
	bullet.bulletTimer += GetFrameTime();
	if (bullet.bulletTimer >= bullet.bulletTimerMax)
	{
		bullet.DrawBullet();
		bulletSpawnVector.y += speed;

		// }
		//bulletSpawnVector.y += speed;
		/*if (active)
		{
			float time = 0;
			time += GetFrameTime();
			if (time += 2.0f)
			{
				active = false;
			}
		}*/

	}
}