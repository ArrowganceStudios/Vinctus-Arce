#pragma once
#include <iostream>
#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
//#include "../GraphicEngine.h"
#include "../../GameEngine.h"

extern GameEngine *gameEngine;

class GraphicEngine;
class GameEngine;

class Font
{
	ALLEGRO_BITMAP *font_set;
	
	int columns;

	int X_CharSize;
	int Y_CharSize;

	int X_Offset;

	int EvaluateOutputSize(std::string text, float scale);
	int GetCharFromTileset(char &c, int &offset);

public:
	Font(const char *filename, int col, int Xchar, int Ychar, int off) : 
		font_set(al_load_bitmap(filename)), columns(col),
		X_CharSize(Xchar), Y_CharSize(Ychar), X_Offset(off){};

	~Font() { al_destroy_bitmap(font_set); }

	ALLEGRO_BITMAP * CreateText(std::string text, float scale);
};