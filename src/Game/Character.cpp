#include "Character.h"
#include "../Globals.h"

Character::~Character()
{
	gameEngine::Instance().GetCollisionDetector()->DestroyHitbox(this); 

}
void Character::Die(){ objectHandler::Instance().DestroyObject(this); };

void Character::Update()
{
	if (!GetHealth())
	{
		SetAlive(false);
		gameEngine::Instance().GetCollisionDetector()->DestroyHitbox(this);

	}
}
/*
Character::Character()
{
}
*/