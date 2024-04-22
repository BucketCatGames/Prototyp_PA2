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

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->UpdateBullet();
	}

	player.SetMousePos();
	player.UpdatePlayer();

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

//void GameInit::DeleteBullets()
//{
//	for (auto it = player.bulletVector.begin(); it != player.bulletVector.end();)
//	{
//		if (it->active == false)
//		{
//			it = player.bulletVector.erase(it);
//		}
//		else
//		{
//			++it;
//		}
//	}
//}