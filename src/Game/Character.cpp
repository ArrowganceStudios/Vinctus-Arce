#include "Character.h"
#include "../Globals.h"


void Character::Update()
{
	if (!GetHealth())
	{
		SetAlive(false);
	}
}

void Character::Die()
{ 
	objectHandler::Instance().DestroyObject(this); 
}
