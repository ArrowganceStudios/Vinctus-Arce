#pragma once
#include "Character.h"

class NPC : public Character
{
public:
	NPC() : Character(), intentToGoDown(false), intentToGoLeft(false), intentToGoRight(false), intentToGoUp(false) {};
	NPC(int initialPower) : power(initialPower), Character(), intentToGoDown(false), intentToGoLeft(false), intentToGoRight(false), intentToGoUp(false) {};

	void SetPower(int nPower) { power = nPower; }
	int GetPower() const { return power; }

	void SetTarget(GameObject* obj) { target = obj; }
	GameObject* GetTarget() const { return target; }

	void Move();

protected:
	void SetIntentToGoDown(bool intent) { intentToGoDown = intent; }
	void SetIntentToGoUp(bool intent) { intentToGoUp = intent; }
	void SetIntentToGoRight(bool intent) { intentToGoRight = intent; }
	void SetIntentToGoLeft(bool intent) { intentToGoLeft = intent; }

	bool WantsToGoDown() const { return intentToGoDown; }
	bool WantsToGoUp() const { return intentToGoUp; }
	bool WantsToGoLeft() const { return intentToGoLeft; }
	bool WantsToGoRight() const { return intentToGoRight; }

private:
	//AIType type;
	int power; //strength/agility/mana of the npc's dmg
	GameObject* target;

	bool intentToGoDown;
	bool intentToGoUp;
	bool intentToGoLeft;
	bool intentToGoRight;

	//more to come
};