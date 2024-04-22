#pragma once
#include "GameControls.h"
#include "Player.h"
#include "iostream"

GameInit::GameInit() {}

GameInit::~GameInit() {}

void GameInit::Draw()
{
	ClearBackground(WHITE);
	player.DrawPlayer(player);
	mouse.BallOnMouse(mouse);
	//bullets.DrawBullet(bullets);
	for (auto& bullet : player.bullets)
	{
		bullet.DrawBullet(bullet);
	}
}

void GameInit::InitFunctions()
{
	player.InitPlayer(player);
	mouse.IsCursorOnScreen(mouse);
	
}

void GameInit::Update()
{
	bullets.UpdateBullet(bullets);
	player.UpdatePlayer(player);
	mouse.GetMousePos(mouse);

	//DeleteBullets();
	std::cout << player.bulletVector.size() << std::endl;
}

void GameInit::HandleInput()
{
	player.PlayerInput();
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		bullets.push_back(player.ShootBullets())
	}
}

void GameInit::DeleteBullets()
{
	for (auto it = player.bulletVector.begin(); it != player.bulletVector.end();)
	{
		if (it->active == false)
		{
			it = player.bulletVector.erase(it);
		}
		else
		{
			++it;
		}
	}
}