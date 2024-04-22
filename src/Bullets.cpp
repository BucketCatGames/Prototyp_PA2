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
Bullets::Bullets()
{

}
void Bullets::DrawBullet(Bullets& bullet)
{
		DrawTexture(bullet.textureBullet, bullet.bulletPosX, bullet.bulletPosY, RAYWHITE);
}

void Bullets::UpdateBullet(Bullets& bullet)
{
	//bulletSpawnVector = Vector2Add(bulletSpawnVector, shootDirVector);
	
		bulletPosY += speed;

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
void Bullets::InitBullets(Bullets& bullet)
{
	Player player = Player();
	Mouse mouse = Mouse();
	bullet.t = 2.0f;
	bullet.bulletSpawnVector = { bullet.bulletPosX, bullet.bulletPosY };
	bullet.bulletSpawnVector = player.PlayerPosVector;
	bullet.bulletPosX = 0;
	bullet.bulletPosY = 0;
//	bullet.shootDirVector = Vector2Subtract(mouse.mousePosVector, player.PlayerPosVector);
	bullet.textureBullet = LoadTexture("assets/graphics/Probe-Schmetterling.png");
	bullet.speed = 5.0f;
	bullet.active = false;
	bullet.bulletTimer = t;
}
