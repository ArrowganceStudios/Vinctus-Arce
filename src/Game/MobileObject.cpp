#include "MobileObject.h"

MobileObject::MobileObject()
{
	//TBI
}

void MobileObject::Init(float x, float y, float velocity)
{
	GameObject::Init(x, y);
	MobileObject::velocity = velocity;
}