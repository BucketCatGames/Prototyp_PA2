#include "PressurePlate.h"

class ExitGate: public PressurePlate
{
public:
	ExitGate() {
		this->texture = LoadTexture("assets/graphics/Ruins_shadow2_1.png");
		this->pos = { 500,200 };
		this->isPressed = false;
	}
};