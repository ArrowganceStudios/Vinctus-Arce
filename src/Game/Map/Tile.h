#pragma once
#include <vector>
#include <allegro5\allegro.h>

class Tile
{
	friend class Map;
private:

	char type;
	bool collidable;

	static ALLEGRO_BITMAP *tileSet;
public:
	Tile(char type, bool collidable) : type(type), collidable(collidable){};
	char GetType(){ return type; }
};