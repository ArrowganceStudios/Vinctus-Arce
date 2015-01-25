#include "MobileObject.h"
#include "../Globals.h"
#include "../Common.h"

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
	CircleType object(GetX(), GetY() - 1, GetHeight() / 2);

	return gameEngine::Instance().GetCollisionDetector()->CanStepOnto(object, Up);
}

bool MobileObject::CanMoveDown()
{
	CircleType object(GetX(), GetY() + 1, GetHeight() / 2);

	return gameEngine::Instance().GetCollisionDetector()->CanStepOnto(object, Down);
}

bool MobileObject::CanMoveLeft()
{
	CircleType object(GetX() - 1, GetY(), GetWidth() / 2);

	return gameEngine::Instance().GetCollisionDetector()->CanStepOnto(object, Left);
}

bool MobileObject::CanMoveRight()
{
	CircleType object(GetX() + 1, GetY(), GetWidth() / 2);

	return gameEngine::Instance().GetCollisionDetector()->CanStepOnto(object, Right);
}