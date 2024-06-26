#pragma once
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"

struct Mouse
{
	// Mouse position
	bool isOnScreen;

	float posX;
	float posY;

	Vector2 mousePosVector;

	void IsCursorOnScreen();
	void BallOnMouse();
};

