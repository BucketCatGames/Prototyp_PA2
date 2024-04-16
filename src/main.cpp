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
	//std::vector<float, float> playerPos = { posX, posY };
	float speed;
	float xVel;
	float yVel;

	Texture2D texture;
};

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
	playerVelocity = Vector2Normalize(playerVelocity);
	player.xVel = playerVelocity.x * player.speed;
	
	player.posX += player.xVel;
	player.posY += player.yVel;
	
}
void DrawPlayer(Player& player)
{
	DrawTexture(player.texture, player.posX, player.posY, BLACK);
}

int main() {
	// Raylib initialization
	// Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
	InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
	SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
	ToggleFullscreen();
#endif

	Player player;
	
	InitPlayer(player);

	// Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		PlayerInput(player);
		UpdatePlayer(player);


		BeginDrawing();
		ClearBackground(WHITE);

		DrawPlayer(player);

		EndDrawing();
	}
	UnloadTexture(player.texture);

	// Close window and OpenGL context
	CloseWindow();

	return EXIT_SUCCESS;
}
