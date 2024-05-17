#pragma once
#include <cstdlib>
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include "config.h"
#include "cmath"
#include <iostream>
#include <string>

class PressurePlate 
{
protected:
	Texture2D texture;
	Vector2 pos;
	bool isPressed;
public:
	PressurePlate() {
		this->texture = LoadTexture("assets/graphics/Rock3_shadow1_1.png");
		this->pos.x = 200;
		this->pos.y = 200;
		this->isPressed = false;
	}
	void drawPressurePlateTexture();
	float getPosX();
	float getPosY();
	bool getIsPressedState();
	void setPressedState(bool);

};
