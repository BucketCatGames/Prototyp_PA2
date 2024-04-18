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

	Player player;
	Mouse mouse;

	Bullets bullets = Bullets(Vector2{ 0, 0 }, Vector2{ 0, 0 }, LoadTexture("assets/graphics/Probe-Schmetterling.png"), 1);


	player.InitPlayer(player);
	

	// Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		GetMousePos(mouse);
		IsCursorOnScreen(mouse);
		player.PlayerInput(player);
		player.UpdatePlayer(player);


	
			
			bullets.UpdateBullet(bullets);
			//bullets.drawable = true;
		


		BeginDrawing();

		ClearBackground(WHITE);
		
		player.DrawPlayer(player);
		BallOnMouse(mouse);

		bullets.DrawBullet();



		EndDrawing();
	}
	//UnloadTexture(texture);

	// Close window and OpenGL context
	CloseWindow();

	return EXIT_SUCCESS;
}