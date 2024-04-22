#pragma once
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include "Player.h"
#include "Mouse.h"
#include "Bullets.h"
#include "GameControls.h"



int main() {
	// Raylib initialization
	// Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
	InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
	SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
	ToggleFullscreen();
#endif

	GameInit game;
	Bullets bullets;

	game.InitFunctions();

	// Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		game.HandleInput();
		game.Update();

		BeginDrawing();
		game.Draw();

		EndDrawing();
	}
	//UnloadTexture(texture);

	// Close window and OpenGL context
	CloseWindow();

	return EXIT_SUCCESS;
}