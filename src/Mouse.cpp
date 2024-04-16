#include "Mouse.h"
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"


void GetMousePos(Mouse& mouse)
{
	mouse.posX = GetMouseX();
	mouse.posY = GetMouseY();
	mouse.isOnScreen = false;

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

