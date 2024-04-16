#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include "Player.h"

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
