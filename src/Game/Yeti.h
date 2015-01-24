#pragma once
#include "NPC.h"
#include "NPCSheet.h"

class Yeti : public NPC
{
public:
	Yeti();
	~Yeti();
private:
	static int counter;
};