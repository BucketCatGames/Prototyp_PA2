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

	//Health
	
	currentHealth = 100;
	maxHealth = 100;
}

void Player::AddHealth(int amount)
{
	currentHealth += amount;
}

void Player::SubHealth(int amount)
{
	currentHealth -= amount;
	if (currentHealth <= 0)
	{
		currentHealth = 0;
		isAlive = false;
	}
}

void Player::UpdatePlayer()
{
	if (isAlive == true)
	{
		PlayerPosVector.x += PlayerVelVector.x;
	PlayerPosVector.y += PlayerVelVector.y;
	}
}

void Player::PlayerInput()
{
	if(isAlive == true)
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
}

void Player::DrawPlayer()
{
	if (isAlive == true)
	{
		DrawTextureRec(texture,{(float)texture.width/2,float(texture.height/2),32,32}, {posX+texture.width/2, posY+texture.height/2}, WHITE);
	}
	
}

void Player::DrawHealth()
{
	DrawText(TextFormat("Health: %i", currentHealth), 10, 10, 20, RED);
}

Bullets* Player::ShootBullets()
{
	if (isAlive == true)
	{
		Bullets* bullet = new Bullets({ posX + texture.width / 2, posY + texture.height / 2 },
			MousePosVector, LoadTexture("assets/graphics/Probe-Schmetterling.png"), 30, GetFrameTime(), 10.0f, 2.0f, 2, 2.0f);
			SubHealth(bullet->bulletCost);
		return bullet;
	}
}

void Player::SetMousePos()
{
	MousePosVector = GetMousePosition();
}

Vector2 Player::GetPlayerPos()
{
	return PlayerPosVector;
}
