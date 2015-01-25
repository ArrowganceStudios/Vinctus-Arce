#include "NPC.h"

void NPC::Move()
{
	if (WantsToGoDown() && CanMoveDown())
		MoveDown();
	else if (WantsToGoUp() && CanMoveUp())
		MoveUp();

	if (WantsToGoLeft() && CanMoveLeft())
		MoveLeft();
	else if (WantsToGoRight() && CanMoveRight())
		MoveRight();
}