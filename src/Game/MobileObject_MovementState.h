#pragma once
#include <vector>
#include "../GameEngine.h"


class MobileObject_MovementState
{
private:
	vector<MobileObject_MovementState *> statelist;
public:
	MobileObject_MovementState();

	/*static WalkRight_State WalkRight;
	static WalkLeft_State WalkLeft;
	static WalkUp_State WalkUp;
	static WalkDown_State WalkDown;*/

	virtual void Init();
	void Cleanup();

	void virtual Update() = 0;


};