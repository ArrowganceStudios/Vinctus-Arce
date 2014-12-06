#include "StaticObject.h"


StaticObject::StaticObject()
{
	StaticObject::x = 0;
	StaticObject::y = 0;
}

void StaticObject::Init(float x, float y)
{
	GameObject::x = x;
	GameObject::y = y;
}