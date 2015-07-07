#pragma once
#include "../StaticGraphic.h"

class StaticGraphic;

class UIElement : public StaticGraphic
{
protected:
	UIElement(float x, float y) :x(x), y(y) {};
	UIElement(float x, float y, float h, float w) :x(x), y(y), StaticGraphic(h, w) {};

	float x;
	float y;

public:
	float GetX() const { return x; }
	float GetY() const { return y; }
};
