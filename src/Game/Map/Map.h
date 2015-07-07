#pragma once
#include <vector>
#include <string>
#include <allegro5/allegro.h>
#include "Tile.h"

class Map : public StaticGraphic
{
	friend class MapLayer;
private:
	void GenerateMap(std::string mapFilepath);
	char GetTileTypeFromColor(ALLEGRO_COLOR color);

	float mapWidth;
	float mapHeight;

	float x;
	float y;

	int tilesAmountX;
	int tilesAmountY;

	std::vector<std::vector<Tile*>> tileMap;

public:
	Map(std::string maptemplatePath, std::string tilesetPath);
	~Map();

	void GenerateBitmap(std::string tilesetPath);
	void Init();
};
