#include "MovableObject.h"

void MovableObject::drawMovableObjectTexture()
{
	DrawTexture(this->texture, pos.x, pos.y, WHITE);
}