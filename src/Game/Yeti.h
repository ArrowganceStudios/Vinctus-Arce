#pragma once
#include "NPC.h"
#include "NPCSheet.h"

class Yeti : public NPC
{
public:
	Yeti();
	~Yeti();

	void Update();
private:
	static int counter;
};