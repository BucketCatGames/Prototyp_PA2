#pragma once
#include "GameControls.h"
#include "Player.h"

GameInit::GameInit() {}

GameInit::~GameInit() {}

void GameInit::Draw()
{
	ClearBackground(WHITE);
	player.DrawPlayer(player);
	mouse.BallOnMouse(mouse);
	bullets.DrawBullet(bullets);
}

void GameInit::InitFunctions()
{
	player.InitPlayer(player);
	mouse.IsCursorOnScreen(mouse);
	bullets.InitBullets();
}

void GameInit::Update()
{
	bullets.UpdateBullet(bullets);
	player.UpdatePlayer(player);
	mouse.GetMousePos(mouse);
}

void GameInit::HandleInput()
{
	player.PlayerInput(player);
}