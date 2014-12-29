#include "MobileObject.h"

MobileObject::MobileObject()
{
	MobileObject::x = 0;
	MobileObject::y = 0;
	MobileObject::velocity = 0;
}

void MobileObject::Init(float x, float y, float velocity)
{
	GameObject::Init(x, y);
	MobileObject::velocity = velocity;
}

void MobileObject::MoveUp()
{
	y += velocity;
}

void MobileObject::MoveDown()
{
	y -= velocity;
}

void MobileObject::MoveLeft()
{
	x -= velocity;
}

void MobileObject::MoveRight()
{
	x += velocity;
}