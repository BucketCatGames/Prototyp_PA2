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

class MovableObject
{
protected:
	Texture2D texture;
	Vector2 pos;
public:
	MovableObject() {
		this->texture = LoadTexture("assets/graphics/Fetus_shadow2_3.png");
		pos.x = 200;
		pos.y = 300;
	}
	void drawMovableObjectTexture();
	void setPos(Vector2);
	Vector2 getPos();
	float getPosX();
	float getPosY();
};
