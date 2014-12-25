#pragma once
#include <string>
#include <vector>
#include "../../Map/Map.h"
#include "../Layer.h"

class MapLayer : public Layer
{
protected:
	Map *myLevel;
	char GetTileTypeAtCoords(float x, float y);
public:
	void Init(std::string maptemplatePath, std::string tilesetPath);
	void Render();
};