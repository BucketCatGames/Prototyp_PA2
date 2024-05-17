#include "PressurePlate.h"

void PressurePlate::drawPressurePlateTexture()
{
	DrawTexture(this->texture, pos.x, pos.y, WHITE);
}