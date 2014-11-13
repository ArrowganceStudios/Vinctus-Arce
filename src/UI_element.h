#pragma once

class UI_element
{

protected:
	UI_element(float x, float y) :x(x), y(y) {};
	int height;
	int width;

	float x;
	float y;

};