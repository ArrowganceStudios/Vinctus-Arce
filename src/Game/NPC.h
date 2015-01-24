#pragma once
#include "Character.h"

class NPC : public Character
{
public:
	NPC() : Character() {};
	NPC(int initialPower) : power(initialPower), Character() {};

	void SetPower(int nPower) { power = nPower; }
	int GetPower() const { return power; }

	void SetTarget(GameObject* obj) { target = obj; }
	GameObject* GetTarget() const { return target; }

private:
	//AIType type;
	int power; //strength/agility/mana of the npc's dmg
	GameObject* target;
	//more to come
};