#pragma once
#include <vector>
#include <allegro5\allegro.h>
#include "../../Graphics/StaticGraphic.h"

class Tile //: StaticGraphic
{
	friend class Map;
private:

	char type;
	bool collidable;

	static ALLEGRO_BITMAP *tileSet;
	//~Tile() { al_destroy_bitmap(tileSet); }
public:
	Tile(char type);
	char GetType() const { return type; }
	bool GetCollidable() const { return collidable; }
};