#pragma once
#include "GameObject.h"
#include <iostream>
#include "MobileObject_MovementState.h"

class MobileObject : public GameObject
{
private:
	MobileObject* movementState; // what is this0
	MobileObject* attackState; //and this
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