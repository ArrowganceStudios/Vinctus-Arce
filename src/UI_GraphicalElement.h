#pragma once
#include <vector>
#include <allegro5\allegro.h>

class UI_GraphicalElement
{
	ALLEGRO_BITMAP *image;
	std::vector <UI_GraphicalElement*> graphics;
public:
	UI_GraphicalElement();
	ALLEGRO_BITMAP* Get_Bitmap_Image() { return image; }
};