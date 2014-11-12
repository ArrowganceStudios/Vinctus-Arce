#pragma once
#include "GameObject.h"
#include <iostream>
#include "MobileObject_MovementState.h"

class MobileObject : public GameObject
{
private:
	MobileObject* movementState;
	MobileObject* attackState;
protected:
	float velocity;

public:
	MobileObject();

	void Init(float x, float y, float velocity);

	float GetVelocity() const { return velocity; }
	float SetVelocity(float vel) { velocity = vel; }

	void virtual Update() {};
	void virtual Render() {};
};