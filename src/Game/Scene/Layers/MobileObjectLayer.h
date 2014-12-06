#pragma once
#include <vector>
#include "../../GameObject.h"
#include "../../ObjectHandler.h"
#include "../Layer.h"

class MobileObjectLayer : public Layer
{
protected:
	//std::vector<GameObject*> actorList;

public:
	/*
	void AddActor(const char* type, float x, float y);
	void AddProjectile(const char* type, float x, float y);
	void AddHitbox(const char* type, float x, float y);
	*/
	void Init();
	void Update();
	void Render();
};