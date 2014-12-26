#include "../../Globals.h"
#include "Map.h"

using namespace TileSize;

Map::Map(std::string maptemplatePath, std::string tilesetPath)
{
	GenerateMap(maptemplatePath);
	width = mapWidth;
	height = mapHeight;

	z = 0;
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;

	GenerateBitmap(tilesetPath);

	graphicEngine::Instance().CreateGraphicInstance(this);
	Show();
}

Map::~Map()
{
	graphicEngine::Instance().DestroyGraphicInstance(this);
	graphicEngine::Instance().DestroyGraphic("class Map");


}

void Map::GenerateMap(std::string mapFilepath)
{
	ALLEGRO_BITMAP *mapFile = al_load_bitmap(mapFilepath.c_str());

	tilesAmountX = al_get_bitmap_width(mapFile);
	tilesAmountY = al_get_bitmap_height(mapFile);

	mapWidth = tilesAmountX * tileWidth;
	mapHeight = tilesAmountY * tileHeight;

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

void Map::GenerateBitmap(std::string tilesetPath)
{
	ALLEGRO_BITMAP *output;
	ALLEGRO_BITMAP *tileset = al_load_bitmap(tilesetPath.c_str());
	output = al_create_bitmap(mapWidth, mapHeight);
	al_set_target_bitmap(output);

	for (int i = 0; i < tileMap.size(); i++)
	{
		for (int j = 0; j < tileMap[i].size(); j++)
		{
			al_draw_bitmap_region(tileset, tileWidth * tileMap[i].at(j)->GetType(), 0, tileWidth, tileHeight, i * tileWidth, j * tileHeight, 0);
		}
	}

	al_set_target_bitmap(al_get_backbuffer(gameEngine::Instance().GetDisplay()));
	graphicEngine::Instance().DefineGraphic("class Map", output);

}