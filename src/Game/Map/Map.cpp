#include "../../Globals.h"
#include "Map.h"

void Map::GenerateMap(std::string mapFilepath)
{
	ALLEGRO_BITMAP *mapFile = al_load_bitmap(mapFilepath.c_str());

	tilesAmountX = al_get_bitmap_width(mapFile);
	tilesAmountY = al_get_bitmap_height(mapFile);

	mapWidth = tilesAmountX * TileSize::tileWidth;
	mapHeight = tilesAmountX * TileSize::tileHeight;

	for (int i = 0; i < tilesAmountX; i++)
	{
		std::vector<Tile*> tileVector(tilesAmountY);
		int j = 0;
		for (unsigned int j = 0; j < tileVector.size(); j++)
		{
			ALLEGRO_COLOR pixelColor = al_get_pixel(mapFile, i, j);
			tileVector.at(j) = new Tile(GetTileTypeFromColor(pixelColor));
		}
		tileMap.push_back(tileVector);
	}
}

char Map::GetTileTypeFromColor(ALLEGRO_COLOR color)
{
	unsigned char r, g, b;
	al_unmap_rgb(color, &r, &g, &b);
	if (r == 255 && g == 255 && b == 255)	// white - open space
		return 0;
	else if (r == 0 && g == 0 && b == 0)	// black - wall
		return 1;
	else return 0;
}