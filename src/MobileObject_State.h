#pragma once
#include <vector>
#include "GameEngine.h"


class MobileObject_State
{
private:
	vector<MobileObject_State *> statelist;
public:
	MobileObject_State();

	/*static WalkRight_State WalkRight;
	static WalkLeft_State WalkLeft;
	static WalkUp_State WalkUp;
	static WalkDown_State WalkDown;
	static Melee_State Melee;
	static Fire_State Fire;*/

	virtual void Init();
	void Cleanup();

	void virtual Update() = 0;
	void virtual Render() = 0;


};