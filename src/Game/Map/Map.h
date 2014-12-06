#pragma once
#include <vector>
#include <allegro5\allegro.h>
#include "Tile.h"

class Map
{
	friend class MapLayer;
public:
	void GenerateMap(ALLEGRO_BITMAP *mapFile);

	float mapWidth;
	float mapHeight;

	int tilesAmountX;
	int tilesAmountY;

	std::vector<std::vector<Tile*>> tileMap;
public:
	Map(ALLEGRO_BITMAP *mapFile){ GenerateMap(mapFile); }
	void Init();
};