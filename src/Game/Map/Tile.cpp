#include "Tile.h"

Tile::Tile(char type) : type(type)
{
	switch (type)
	{
	case 0:
		collidable = false;
		break;
	case 1:
		collidable = true;
		break;
	default:
		break;
	}
		
}