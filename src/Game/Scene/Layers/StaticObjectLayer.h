#pragma once
#include <vector>
#include "../../GameObject.h"
#include "../../ObjectHandler.h"
#include "../Layer.h"

class StaticObjectLayer : public Layer
{
protected:
	//std::vector<GameObject*> objectList;
public:
	/*
	void AddObject(const char* type, float x, float y);
	*/
	void Init();
	void Update();
	void Render();
};