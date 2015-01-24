#pragma once
#include "NPC.h"
#include "NPCSheet.h"

class Yeti : public NPC
{
public:
	Yeti();
	~Yeti();
	
	int GetMeleeStrikeDamage();

	void AI();

	void Update();
private:
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void MeleeAttack();

	static int counter;
};