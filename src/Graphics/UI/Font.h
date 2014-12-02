#pragma once
#include <iostream>
#include <string>
#include <map>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "../../GameEngine.h"

extern GameEngine *gameEngine;

class GraphicEngine;
class GameEngine;

class Font
{
	ALLEGRO_BITMAP *font_set;
	std::map<char, std::pair<int, int>> alphabet;

	int columns;

	int X_CharSize;
	int Y_CharSize;

	int X_Offset;

	void InitializeAlphabet(std::map<char, std::pair<int, int>> &alphabet);

	int EvaluateOutputSize(std::string text, float scale);

	int GetCharFromTileset(char &c);
	int GetOffsetFromTileset(char &c);

public:
	Font(const char *filename, int col, int Xchar, int Ychar, int off) : 
		font_set(al_load_bitmap(filename)), columns(col),
		X_CharSize(Xchar), Y_CharSize(Ychar), X_Offset(off)
	{
		InitializeAlphabet(alphabet);
	};

	~Font() { al_destroy_bitmap(font_set); }

	ALLEGRO_BITMAP * CreateText(std::string text, float scale);
};