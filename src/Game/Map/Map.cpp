#include "../../Globals.h"
#include "Map.h"

void Map::GenerateMap(ALLEGRO_BITMAP *mapFile)
{
	tilesAmountX = al_get_bitmap_width(mapFile);
	tilesAmountY = al_get_bitmap_height(mapFile);

	mapWidth = tilesAmountX * TileSize::tileWidth;
	mapHeight = tilesAmountX * TileSize::tileHeight;

	for (int i = 0; i < tilesAmountX; i++)
	{
		std::vector<Tile*> tileVector(tilesAmountY);
		tileMap.push_back(tileVector);
		for (auto tileit : tileMap[i])
		{
			// cases for adding different tile types
		}
	}
}