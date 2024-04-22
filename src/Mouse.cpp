#pragma once
#include "h"
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include "Player.h"

//void Mouse::Update()
//{
//	GetMousePos(*this);
//	IsCursorOnScreen(*this);
//}
//void Mouse::GetMousePos()
//{
//	Vector2 mousePosVector = GetMousePosition();
//}

void Mouse::IsCursorOnScreen()
{
	posX = GetMouseX();
	posY = GetMouseY();


	if (posX >= 0 && posX <= GetScreenWidth() && posY >= 0 && posY <= GetScreenHeight())
	{
		isOnScreen = true;
	}
	else
	{
		isOnScreen = false;
	}
}

void Mouse::BallOnMouse()
{
	mousePosVector = GetMousePosition();
	DrawCircleV(mousePosVector, 20, RED);
}