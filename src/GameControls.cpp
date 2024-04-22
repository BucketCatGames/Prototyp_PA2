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
	mouse.BallOnMouse();
	//bullets.DrawBullet(bullets);
	for (auto& bullet : bullets)
	{
		bullet->DrawBullet();
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
	player.UpdatePlayer();

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->UpdateBullet();
		DeleteBullets();
	}

	player.SetMousePos();

	if (bullets.size() > 0)
	{
		std::cout << bullets[0]->bulletPosX << std::endl;
	}
}

void GameInit::HandleInput()
{
	player.PlayerInput();
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		bullets.push_back(player.ShootBullets());
	}
}

void GameInit::DeleteBullets()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->bulletPosX > GetScreenWidth() || bullets[i]->bulletPosX < 0 || bullets[i]->bulletPosY > GetScreenHeight() || bullets[i]->bulletPosY < 0)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
			std::cout << "Bullet deleted" << std::endl;
		}
		bullets[i]->bulletTimer += GetFrameTime();
		if (bullets[i]->bulletTimer >= bullets[i]->bulletTimerMax)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
			std::cout << "Bullet deleted timer" << std::endl;
		}
	}
}


