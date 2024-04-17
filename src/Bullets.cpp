#pragma once
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include "Bullets.h"


void DrawBullet(Bullets& bullet)
{
	bullet.textureBullet = LoadTexture("assets/graphics/Probe-Schmetterling.png");
}

void ShootBullet(Player& player, Mouse& mouse, Bullets& bullet)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 shootDirVector;
		shootDirVector = Vector2Subtract(mouse.mousePosVector, player.playerPosVector);
		shootDirVector = bullet.shootDirVector;

		/*Bullets bullet;
		bullet.bulletSpawnVector = player.playerPosVector;
		bullet.shootDirVector = Vector2Subtract(mouse.mousePosVector, player.playerPosVector);
		bullet.shootDirVector = Vector2Normalize(bullet.shootDirVector);
		bullet.shootDirVector = Vector2Scale(bullet.shootDirVector, 10);*/
	}
}

void UpdateBullet(Bullets& bullet)
{
	bullet.bulletSpawnVector = Vector2Add(bullet.bulletSpawnVector, bullet.shootDirVector);
	DrawTexture(bullet.textureBullet, bullet.bulletSpawnVector.x, bullet.bulletSpawnVector.y, WHITE);
}