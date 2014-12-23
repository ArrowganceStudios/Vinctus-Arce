#pragma once
#include <vector>
#include <string>
#include <allegro5\allegro.h>
#include "Tile.h"

class Map
{
	friend class MapLayer;
private:
	void GenerateMap(std::string mapFilepath);
	char GetTileTypeFromColor(ALLEGRO_COLOR color);

	float mapWidth;
	float mapHeight;

	int tilesAmountX;
	int tilesAmountY;

	std::vector<std::vector<Tile*>> tileMap;
public:
	Map(std::string path){ GenerateMap(path); }
	void Init();
};