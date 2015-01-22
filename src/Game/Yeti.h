#pragma once
#include "NPC.h"
#include "NPCSheet.h"

class Yeti : public NPC
{
public:
	Yeti();
	~Yeti();

	void MeleeAttack();
	int GetMeleeStrikeDamage();

	void AI();
	void SetTarget(GameObject *target) { Yeti::target = target; }

	static int GetCounter() { return counter; }

	void Update();
private:
	static int counter;

	GameObject *target;
};