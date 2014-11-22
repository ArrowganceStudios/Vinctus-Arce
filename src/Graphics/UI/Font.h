#pragma once
#include <iostream>
#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

class Font
{
	ALLEGRO_BITMAP *font_set;
	
	int columns;

	int X_CharSize;
	int Y_CharSize;

	int X_Offset;

	int GetCharFromTileset(char &c);

public:
	Font(const char *filename, int col, int Xchar, int Ychar, int off) : font_set(al_load_bitmap(filename)), columns(col),
		X_CharSize(Xchar), Y_CharSize(Ychar), X_Offset(off){};
	~Font()
	{
		al_destroy_bitmap(font_set);
	}

	ALLEGRO_BITMAP* Create_Text(std::string text, float scale);


};