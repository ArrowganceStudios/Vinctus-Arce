#include "GameObject.h"

GameObject::GameObject()
{
	x = 0;
	y = 0;
}

void GameObject::Init(float x, float y)
{
	GameObject::x = x;
	GameObject::y = y;
}