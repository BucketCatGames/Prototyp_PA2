#pragma	once
#include "Player.h"
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"

Player::Player()
{

}
Player::~Player()
{
	UnloadTexture(texture);
};

void Player::InitPlayer(Player& player)
{
	player.posX = 100;
	player.posY = 100;
	player.speed = 5;
	player.xVel = 0;
	player.yVel = 0;
	texture = LoadTexture("assets/graphics/testimage.png");
	player.PlayerPosVector = { player.posX, player.posY };
	player.PlayerVelVector = { player.xVel, player.yVel };
}

void Player::UpdatePlayer(Player& player)
{
	player.PlayerPosVector.x += player.PlayerVelVector.x;
	player.PlayerPosVector.y += player.PlayerVelVector.y;

}

void Player::PlayerInput(Player& player)
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
	Vector2 playerPosVector = player.PlayerPosVector;
	playerVelocity = Vector2Normalize(playerVelocity);
	player.xVel = playerVelocity.x * player.speed;

	player.posX += player.xVel;
	player.posY += player.yVel;

}

void Player::DrawPlayer(Player& player)
{
	DrawTexture(player.texture, player.posX, player.posY, BLACK);
}

//void Player::ShootBullets(Player& player, Bullets& bullets)
//{
//	bulletVector.push_back(Bullets({ playerPosVector.x + player.texture.width / 2, playerPosVector.y + player.texture.height / 2 },
//		bullets.shootDirVector, bullets.textureBullet, -7, player));
//}
