#pragma once
#include "GameControls.h"
#include "Player.h"

GameInit::GameInit() {}

GameInit::~GameInit() {}

void GameInit::Draw()
{
	player.DrawPlayer(player);
	bullets.DrawBullet(bullets);
	mouse.BallOnMouse(mouse);
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