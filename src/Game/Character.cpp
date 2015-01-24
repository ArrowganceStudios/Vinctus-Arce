#include "Character.h"
#include "../Globals.h"

void Character::Update()
{
	if (!GetHealth())
		Die();
}

void Character::Die()
{ 
	SetAlive(false);
	gameEngine::Instance().GetCollisionDetector()->DestroyHitbox(this);
	gameEngine::Instance().GetCollisionDetector()->DestroyAttack(this);
}