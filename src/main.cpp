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



int main() {
	// Raylib initialization
	// Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
	InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
	SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
	ToggleFullscreen();
#endif

	Player player;
	Mouse mouse;
	Bullets bullets;

	InitPlayer(player);

	// Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		GetMousePos(mouse);
		IsCursorOnScreen(mouse);
		PlayerInput(player);
		UpdatePlayer(player);

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			InitBullet(player, mouse, bullets);
			BulletTexture(bullets);
		}

		BeginDrawing();

		ClearBackground(WHITE);
		UpdateBullet(bullets);
		DrawPlayer(player);
		BallOnMouse(mouse);
		DrawBullet(bullets);

		EndDrawing();
	}
	UnloadTexture(player.texture);

	// Close window and OpenGL context
	CloseWindow();

	return EXIT_SUCCESS;
}