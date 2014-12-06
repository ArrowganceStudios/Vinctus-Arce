#pragma once
#include "GameObject.h"
//#include "MobileObject_MovementState.h"

class MobileObject : public GameObject
{
private:
	/*MobileObject_MovementState* movementState;
	MobileObject_AttackState* attackState;*/
protected:
	float velocity;

public:
	MobileObject();

	void Init(float x, float y, float velocity);

	float GetVelocity() const { return velocity; }
	float SetVelocity(float vel) { velocity = vel; }

	void virtual Update() {};
};