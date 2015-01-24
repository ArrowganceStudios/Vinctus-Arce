#pragma once
#include "Character.h"

class NPC : public Character
{
public:
	NPC() : Character() {};
	NPC(int initialPower) : power(initialPower), Character() {};

	void SetPower(int nPower) { power = nPower; }
	int GetPower() const { return power; }

private:
	//AIType type;
	int power; //strength/agility/mana of the npc's dmg
	//more to come
};