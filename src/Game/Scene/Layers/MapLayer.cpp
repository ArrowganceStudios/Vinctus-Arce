#include "../../../Globals.h"
#include "MapLayer.h"

using namespace TileSize;

MapLayer::~MapLayer()
{
	delete myLevel;
}

char MapLayer::GetTileTypeAtCoords(float x, float y)
{
	if (myLevel != nullptr)
	{
		int tileX = x / tileWidth;
		int tileY = y / tileHeight;

		return myLevel->tileMap[tileX].at(tileY)->GetType();
	}
	else return 0;
}

RectangleType MapLayer::GetTileMeshAt(float x, float y)
{
	if (myLevel != nullptr)
	{
		Point center;
		center.x = (((int)x / (int)tileWidth) + 0.5) * tileWidth;
		center.y = (((int)y / (int)tileHeight) + 0.5) * tileHeight;

		return RectangleType(center.x, center.y, tileWidth, tileHeight);
	}
	else 
		return RectangleType(-1, -1, 0, 0);
}

void MapLayer::Init(std::string maptemplatePath, std::string tilesetPath)
{
	myLevel = new Map(maptemplatePath, tilesetPath);
}

void MapLayer::Render()
{
	// ???
}