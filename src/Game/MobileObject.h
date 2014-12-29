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

	bool CanMoveUp();
	bool CanMoveDown();
	bool CanMoveLeft();
	bool CanMoveRight();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	void virtual Update() {};
};