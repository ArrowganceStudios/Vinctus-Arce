#include "MobileObject.h"
#include "../Globals.h"

MobileObject::MobileObject()
{
	MobileObject::x = 0;
	MobileObject::y = 0;
	MobileObject::velocity = 0;
	MobileObject::directionX = 0;
	MobileObject::directionY = 0;
}

void MobileObject::Init(float x, float y, float velocity)
{
	GameObject::Init(x, y);
	MobileObject::velocity = velocity;
}

void MobileObject::Move()
{
	if (CanMoveUp())
		MoveUp();
	else if (CanMoveDown())
		MoveDown();

	if (CanMoveLeft())
		MoveLeft();
	else if (CanMoveRight())
		MoveRight();
}

void MobileObject::MoveUp()
{
	y++;
}

void MobileObject::MoveDown()
{
	y--;
}

void MobileObject::MoveLeft()
{
	x--;
}

void MobileObject::MoveRight()
{
	x++;
}

bool MobileObject::CanMoveUp()
{
	return gameEngine::Instance().GetCollisionDetector()->CanStepOnto(
		GetX(), GetX() + GetWidth(), GetY() - 1, GetY() - 1 + GetHeight()
		);
}

bool MobileObject::CanMoveDown()
{
	return gameEngine::Instance().GetCollisionDetector()->CanStepOnto(
		GetX(), GetX() + GetWidth(), GetY() + 1, GetY() + 1 + GetHeight()
		);
}

bool MobileObject::CanMoveLeft()
{
	return gameEngine::Instance().GetCollisionDetector()->CanStepOnto(
		GetX() - 1, GetX() - 1 + GetWidth(), GetY(), GetY() + GetHeight()
		);
}

bool MobileObject::CanMoveRight()
{
	return gameEngine::Instance().GetCollisionDetector()->CanStepOnto(
		GetX() + 1, GetX() + 1 + GetWidth(), GetY(), GetY() + GetHeight()
		);
}