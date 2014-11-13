#pragma once
#include <vector>
#include <allegro5\allegro.h>

class UI_GraphicalElement
{
	std::vector <ALLEGRO_BITMAP*> UI_elements_images;
public:
	UI_GraphicalElement(){};
	ALLEGRO_BITMAP* Set_Bitmap_Image(std::vector <ALLEGRO_BITMAP*> images) { UI_elements_images = images; }
};