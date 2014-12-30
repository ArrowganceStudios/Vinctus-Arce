#pragma once
#include <map>
#include <string>
#include "Font.h"

using namespace std;

class Font;

class TextManager
{
private:
	map <string, Font *> fonts;

public:
	~TextManager() { if (fonts.size()) for (auto &elem : fonts) if (elem.second != nullptr) delete elem.second; }
	void DefineFont(string fontName, string filePath, int col, int Xchar, int Ychar, int off);
	ALLEGRO_BITMAP * CreateText(string text, string fontName, float scale);
};