#pragma once
#include "Player.h"
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include "Bullets.h"

Player::Player()
{
	InitPlayer();
}
Player::~Player()
{
	UnloadTexture(texture);
};

void Player::InitPlayer()
{
	posX = 100;
	posY = 100;
	speed = 5;
	xVel = 0;
	yVel = 0;
	texture = LoadTexture("assets/graphics/testimage.png");
	PlayerPosVector = {posX, posY};
	PlayerVelVector = {xVel, yVel};
}

void Player::UpdatePlayer()
{
	PlayerPosVector.x += PlayerVelVector.x;
	PlayerPosVector.y += PlayerVelVector.y;
}

void Player::PlayerInput()
{
	if (IsKeyDown(KEY_W))
	{
		yVel = -speed;
	}
	else if (IsKeyDown(KEY_S))
	{
		yVel = speed;
	}
	else
	{
		yVel = 0;
	}

	if (IsKeyDown(KEY_A))
	{
		xVel = -speed;
	}
	else if (IsKeyDown(KEY_D))
	{
		xVel = speed;
	}
	else
	{
		xVel = 0;
	}

	posX = Clamp(posX, 0.0f, GetScreenWidth() - texture.width);
	posY = Clamp(posY, 0.0f, GetScreenHeight() - texture.height);

	Vector2 playerVelocity = {xVel, yVel};
	Vector2 playerPosVector = PlayerPosVector;
	playerVelocity = Vector2Normalize(playerVelocity);
	xVel = playerVelocity.x * speed;

	posX += xVel;
	posY += yVel;
}

void Player::DrawPlayer()
{
	DrawTexture(texture, posX, posY, BLACK);
}

Bullets* Player::ShootBullets()
{
	
	Bullets* bullet = new Bullets({ posX + texture.width / 2, posY + texture.height / 2 }, 
										MousePosVector, LoadTexture("assets/graphics/Probe-Schmetterling.png"), 5, GetFrameTime(), 0.5f);

	return bullet;
}

void Player::SetMousePos()
{
	MousePosVector = GetMousePosition();
}