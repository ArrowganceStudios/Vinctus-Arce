#pragma once
#include <vector>
#include <allegro5\allegro.h>

class UI_GraphicalElement
{
private:
	ALLEGRO_BITMAP *image;
	std::vector <UI_GraphicalElement*> graphics;
	UI_GraphicalElement();
public:
};