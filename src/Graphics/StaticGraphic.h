#pragma once
#include "Graphic.h"

class StaticGraphic : public Graphic
{
public:
	StaticGraphic() {};
	StaticGraphic(float h, float w) : Graphic(h, w) {};

};