#pragma	once
#include "Player.h"
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"

void InitPlayer(Player& player)
{
	player.posX = 100;
	player.posY = 100;
	player.speed = 5;
	player.xVel = 0;
	player.yVel = 0;

	player.texture = LoadTexture("assets/graphics/testimage.png");
}

void UpdatePlayer(Player& player)
{
	player.posX += player.xVel;
	player.posY += player.yVel;
}

void PlayerInput(Player& player)
{
	if (IsKeyDown(KEY_W))
	{
		player.yVel = -player.speed;
	}
	else if (IsKeyDown(KEY_S))
	{
		player.yVel = player.speed;
	}
	else
	{
		player.yVel = 0;
	}

	if (IsKeyDown(KEY_A))
	{
		player.xVel = -player.speed;
	}
	else if (IsKeyDown(KEY_D))
	{
		player.xVel = player.speed;
	}
	else
	{
		player.xVel = 0;
	}

	player.posX = Clamp(player.posX, 0.0f, GetScreenWidth() - player.texture.width);
	player.posY = Clamp(player.posY, 0.0f, GetScreenHeight() - player.texture.height);

	Vector2 playerVelocity = { player.xVel, player.yVel };
	Vector2 playerPosVector = player.playerPosVector;
	playerVelocity = Vector2Normalize(playerVelocity);
	player.xVel = playerVelocity.x * player.speed;

	player.posX += player.xVel;
	player.posY += player.yVel;

}

void DrawPlayer(Player& player)
{
	DrawTexture(player.texture, player.posX, player.posY, BLACK);
}