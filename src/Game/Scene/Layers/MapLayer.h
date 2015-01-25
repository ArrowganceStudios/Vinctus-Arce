#pragma once
#include <string>
#include <vector>
#include "../../Map/Map.h"
#include "../Layer.h"
#include "../../../Common.h"

class MapLayer : public Layer
{
protected:
	Map *myLevel;
public:
	~MapLayer();
	void Init(std::string maptemplatePath, std::string tilesetPath);
	void Render();

	char GetTileTypeAtCoords(float x, float y);
	RectangleType GetTileMeshAt(float x, float y);
};