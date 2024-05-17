#include "MovableObject.h"

void MovableObject::drawMovableObjectTexture()
{
	DrawTexture(this->texture, pos.x, pos.y, WHITE);
}
void MovableObject::setPos(Vector2 inVector)
{
	this->pos = { inVector };
}
Vector2 MovableObject::getPos()
{
	return this->pos;
}
float MovableObject::getPosX()
{
	return this->pos.x;
}
float MovableObject::getPosY()
{
	return this->pos.y;
}