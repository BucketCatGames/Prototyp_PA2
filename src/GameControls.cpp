#pragma once
#include "GameControls.h"
#include "Player.h"
#include "iostream"

GameInit::GameInit() {}

GameInit::~GameInit() {}

void GameInit::Draw()
{
	ClearBackground(WHITE);
	player.DrawPlayer();
	player.DrawHealth();
	mouse.BallOnMouse();
	pressurePlate.drawPressurePlateTexture();
	movableObject.drawMovableObjectTexture();
	
	//bullets.DrawBullet(bullets);
	for (int i = 0; i < enemy.size(); i++) {	//drawt alle Enemies
		enemy[i].drawEnemy();
	}
	for (auto& bullet : bullets)
	{
		bullet->DrawBullet();
	}
	if (player.isAlive == false)
	{
		DrawText("You died", GetScreenWidth() / 2, GetScreenHeight() / 2, 50, RED);
		DeleteAllBullets();
	}
}

void GameInit::InitFunctions()
{
	player.InitPlayer();
	mouse.IsCursorOnScreen();

}

void GameInit::Update()
{
	mouse.IsCursorOnScreen();
	/*player.UpdatePlayer();*/ 
	for (int i = 0; i < enemy.size();i++) {			//aktualisiert das movement von jedem Gegner
		enemy[i].movementToPlayer(player);
	}
		UpdateBullets();
		
	player.SetMousePos();

	if (bullets.size() > 0)
	{
		std::cout << bullets[0]->bulletPosX << std::endl;
	}

	SpawnEnemy();									//checkt Enemy anzahl und spawnt Enemies nach
	EnemyBulletCollision();
	UpdateEnemy();								// das hier nuked momentan das Spiel
	PlayerMovableObjectCollision();
}
void GameInit::UpdateBullets()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->UpdateBullet();
	}
		UpdateTimer();
		//DeleteBullets();
		DeleteBulletsTimer();
		BulletsStopMoving();
		CollectBullets();
}

void GameInit::HandleInput()
{
	player.PlayerInput();
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && player.isAlive == true)
	{
		bullets.push_back(player.ShootBullets());
		
	}
}

void GameInit::DeleteBullets()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->bulletPosX > GetScreenWidth() || bullets[i]->bulletPosX < 0 || bullets[i]->bulletPosY > GetScreenHeight() || bullets[i]->bulletPosY < 0) //?? Was geht hier ab
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
			std::cout << "Bullet deleted" << std::endl;
		}
	}
}
void GameInit::UpdateTimer(){
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->bulletTimer += GetFrameTime();
	}
}
void GameInit::DeleteBulletsTimer()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		
		if (bullets[i]->bulletTimer >= bullets[i]->bulletTimerMax)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
			std::cout << "Bullet deleted timer" << std::endl;
		}
	}
}

void GameInit::BulletsStopMoving()
{
	float multiplier = 0.01f;
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->speed -= bullets[i]->bulletTimer*multiplier;
		if(bullets[i]->speed <= 0)
		{
			bullets[i]->speed = 0;
		}
	}
}

void GameInit::DeleteAllBullets()
{
	for (int i = 0; i < bullets.size(); i++) 
	{
		delete bullets[i];
		bullets.erase(bullets.begin() + i); 
	}
}

void GameInit::CollectBullets() 
{
	for (int i = 0; i < bullets.size(); i++) 
	{
		bullets[i]->bulletTimer += GetFrameTime(); 
		if (bullets[i]->bulletTimer >= bullets[i]->spawnTimer) 
		{
			if (CheckCollisionCircles({ player.posX+25, player.posY+25}, 35, { bullets[i]->bulletPosX+13, bullets[i]->bulletPosY+13 }, 24))
			{
				player.AddHealth(bullets[i]->bulletCost);
				std::cout << "Bullet collected" << std::endl;
				
				delete bullets[i]; 
				bullets.erase(bullets.begin() + i); 
			}
		}
	}
}
void GameInit::SpawnEnemy()
{
	if (enemy.size() < maxEnemyCount)
	{
		Enemy newEnemy;
		enemy.push_back(newEnemy);
	}
}
void GameInit::EnemyBulletCollision() {				//checkt ob Enemy von einer Bullet getroffen wurde und setzt bei Collis
	for (int i = 0; i < enemy.size(); i++)
	{
		for (int u = 0; u < bullets.size(); u++)
		{
			if (CheckCollisionCircles({ enemy[i].getEnemyPosX() + 60, enemy[i].getEnemyPosY() + 60 }, 60, { bullets[u]->bulletPosX + 13, bullets[u]->bulletPosY + 13 }, 24))
			{
				enemy[i].setEnemyHealth(0);		
			}
		}
	}
}
void GameInit::UpdateEnemy()						//deleted enemy 
{
	for (int i = 0; i < enemy.size(); i++)
	{
		if (enemy[i].getEnemyHealth() == 0)
		{
			enemy[i].deleteEnemyTexture();
			enemy.erase(enemy.begin() + i);
		}
	}
}
void GameInit::PlayerMovableObjectCollision()
{
	if (CheckCollisionCircles({ player.posX + 25, player.posY + 25 }, 35, { movableObject.getPosX() + 10,movableObject.getPosY() + 10 }, 18))
	{
		Vector2 playerPos = {player.GetPlayerPosX(), player.GetPlayerPosY()};
		Vector2 objectPos = {movableObject.getPosX(),movableObject.getPosY()};

		Vector2 objectPushDirection = Vector2Normalize(Vector2Subtract(objectPos, playerPos));
		movableObject.setPos(Vector2Add(movableObject.getPos(), objectPushDirection));
	}
}
