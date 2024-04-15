#include <cstdlib>

#include "raylib.h"

#include "config.h"

struct Player
{
	float posX;
	float posY;
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
	//UnloadTexture(myTexture);

	// Close window and OpenGL context
	CloseWindow();

	return EXIT_SUCCESS;
}
