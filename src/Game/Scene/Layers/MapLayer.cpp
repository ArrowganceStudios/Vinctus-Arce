#include "../../../Globals.h"
#include "MapLayer.h"

char MapLayer::GetTileTypeAtCoords(float x, float y)
{
	if (myLevel != nullptr)
	{
		int tileX = x / TileSize::tileWidth;
		int tileY = y / TileSize::tileHeight;
		
		return myLevel->tileMap[tileX].at(tileY)->GetType();
	}
	else return 0;
}

void MapLayer::Init(std::string maptemplatePath, std::string tilesetPath)
{
	myLevel = new Map(maptemplatePath, tilesetPath);
}

void MapLayer::Render()
{
	// ???
}