#pragma once
#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	StaticObject();

	void Init(float x, float y);

	void virtual Update() {};
};