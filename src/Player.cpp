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
	posX = 600;
	posY = 100;
	speed = 5;
	xVel = 0;
	yVel = 0;
	texture = LoadTexture("assets/graphics/testimage.png");
	PlayerPosVector = { posX, posY };
	PlayerVelVector = { xVel, yVel };

	//Health

	currentHealth = 100;
	maxHealth = 100;
}

void Player::AddHealth(int amount)
{
	currentHealth += amount;
}

void Player::SubHealth(int amount)		//Das hier wird nur aufgerufen wenn der Spieler schieﬂt. Der Spieler kann also nur sterben wenn er durch bullets leben verliert.  
{
	currentHealth -= amount;			//Bei dem "nicht Prototypen" sollte hier einfach eine Update healthstate funktion sein die generell checkt ob der Spieler am leben ist
	if (currentHealth <= 0)
	{
		currentHealth = 0;				//ich habe die funktion switchHealthstate() einfach seperat mal inplementiert	-Alex
		isAlive = false;
	}
}

void Player::PlayerInput()
{
	if (isAlive == true)
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

		Vector2 playerVelocity = { xVel, yVel };
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
		Vector2 playerToMouse = Vector2Subtract(MousePosVector, { posX, posY });
		Texture2D spriteRectangles[8];
		float segmentSize = 360.0f / 8.0f;

		float angle = atan2(playerToMouse.y, playerToMouse.x) * RAD2DEG + 90 + 45;
		angle = fmodf(angle, 360.0f);

		if (angle < 0)
		{
			angle += 360.0f;
		}

		int spriteIndex = static_cast<int>(angle / segmentSize) % 8;

		spriteRectangles[0] = LoadTexture("assets/graphics/vor.png");
		spriteRectangles[1] = LoadTexture("assets/graphics/Rechtshoch.png");
		spriteRectangles[2] = LoadTexture("assets/graphics/Rechts.png");
		spriteRectangles[3] = LoadTexture("assets/graphics/rechtsrunter.png");
		spriteRectangles[4] = LoadTexture("assets/graphics/runter.png");
		spriteRectangles[5] = LoadTexture("assets/graphics/linksrunter.png");
		spriteRectangles[6] = LoadTexture("assets/graphics/links.png");
		spriteRectangles[7] = LoadTexture("assets/graphics/linkshoch.png");

		DrawTextureEx(spriteRectangles[spriteIndex], { posX, posY }, 0.0f, 5.0f, WHITE);
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

float Player::GetPlayerPosX()
{
	return posX;
}
float Player::GetPlayerPosY()
{
	return posY;
}
void Player::SetHealth(int _health)
{
	this->currentHealth = _health;
}
void Player::switchHealthState()
{
	if (this->currentHealth <= 0)
	{
		this->isAlive = false;
	}
}
