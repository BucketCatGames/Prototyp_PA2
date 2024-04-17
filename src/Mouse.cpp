#pragma once
#include "Mouse.h"
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
void GetMousePos(Mouse& mouse)
{
	Vector2 mousePosVector = GetMousePosition();
}

void IsCursorOnScreen(Mouse& mouse)
{
	mouse.posX = GetMouseX();
	mouse.posY = GetMouseY();


	if (mouse.posX >= 0 && mouse.posX <= GetScreenWidth() && mouse.posY >= 0 && mouse.posY <= GetScreenHeight())
	{
		mouse.isOnScreen = true;
	}
	else
	{
		mouse.isOnScreen = false;
	}
}

void BallOnMouse(Mouse& mouse)
{
	mouse.mousePosVector = GetMousePosition();
	DrawCircleV(mouse.mousePosVector, 20, RED);
}