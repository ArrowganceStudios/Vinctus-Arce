#pragma once
#include "GameObject.h"
#include <iostream>
#include "MobileObject_State.h"

class MobileObject : public GameObject
{
private:
	bool alive;
	MobileObject* state;
protected:
	float x;
	float y;
	float velocity;

public:
	MobileObject();

	void Init(float x, float y);

	float GetX() const { return x; }
	float GetY() const { return y; }

	void virtual Update() {};
	void virtual Render() {};

	bool IsAlive() const { return alive; }
	void SetAlive(bool alive) { MobileObject::alive = alive; }
	


};