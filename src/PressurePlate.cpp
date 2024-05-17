#include "PressurePlate.h"

void PressurePlate::drawPressurePlateTexture()
{
	DrawTexture(this->texture, pos.x, pos.y, WHITE);
}
float PressurePlate::getPosX()
{
	return this->pos.x;
}
float PressurePlate::getPosY() {
	return this->pos.y;
}
void PressurePlate::setPressedState(bool inPressedState)
{
	this->isPressed = inPressedState; 
}
bool PressurePlate::getIsPressedState()
{
	return this->isPressed;
}