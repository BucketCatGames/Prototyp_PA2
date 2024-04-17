#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"

struct Player
{
	float posX;
	float posY;
	float speed;
	float xVel;
	float yVel;

	Vector2 playerPosVector;

	Texture2D texture;
};

void InitPlayer(Player& player);
void UpdatePlayer(Player& player);
void PlayerInput(Player& player);
void DrawPlayer(Player& player);