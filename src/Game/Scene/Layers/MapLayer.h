#pragma once
#include <vector>
#include "../../Map/Map.h"
#include "../Layer.h"

class MapLayer : public Layer
{
protected:
	Map *myLevel;
	char GetTileTypeAtCoords(float x, float y);
public:
	void Init();
	void Render();
};