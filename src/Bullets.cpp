#pragma once
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include "Bullets.h"


void BulletTexture(Bullets& bullet)
{
	bullet.textureBullet = LoadTexture("assets/graphics/Probe-Schmetterling.png");
}

void InitBullet(Player& player, Mouse& mouse, Bullets& bullet)
{
<<<<<<< HEAD
	Vector2 shootDirVector;
	shootDirVector = Vector2Subtract(mouse.mousePosVector, player.playerPosVector);
	shootDirVector = bullet.shootDirVector;


	bullet.bulletSpawnVector = player.playerPosVector;
	bullet.shootDirVector = Vector2Subtract(mouse.mousePosVector, player.playerPosVector);
	bullet.shootDirVector = Vector2Normalize(bullet.shootDirVector);
	bullet.shootDirVector = Vector2Scale(bullet.shootDirVector, 10);

=======
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
>>>>>>> parent of 3b9e9f5 (Texture drawed; noch keine Bewegung/Rechnung)
}
void DrawBullet(Bullets& bullet)
{
	DrawTexture(bullet.textureBullet, bullet.bulletSpawnVector.x, bullet.bulletSpawnVector.y, RAYWHITE);
}
void UpdateBullet(Bullets& bullet)
{
	bullet.bulletSpawnVector = Vector2Add(bullet.bulletSpawnVector, bullet.shootDirVector);
<<<<<<< HEAD
	DrawTextureV(bullet.textureBullet, bullet.bulletSpawnVector, RAYWHITE);
	//DrawTexture(bullet.textureBullet, 100, 100, RAYWHITE);
}

void ShootBullet(Player& player, Mouse& mouse, Bullets& bullet)
{
	InitBullet(player, mouse, bullet);

=======
	DrawTexture(bullet.textureBullet, bullet.bulletSpawnVector.x, bullet.bulletSpawnVector.y, WHITE);
>>>>>>> parent of 3b9e9f5 (Texture drawed; noch keine Bewegung/Rechnung)
}