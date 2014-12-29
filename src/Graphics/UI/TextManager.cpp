#include "TextManager.h"

void TextManager::DefineFont(string fontName, string filePath, int col, int Xchar, int Ychar, int off)
{
	Font newFont(filePath.c_str(), col, Xchar, Ychar, off);
	
	if (fonts.find(fontName) != fonts.end())
	{
		cerr << "Font already exists!" << endl;
		return;
	}

	fonts.emplace(fontName, newFont);
}

ALLEGRO_BITMAP * TextManager::CreateText(string text, string fontName, float scale = 1)
{
	if (fonts.find(fontName) != fonts.end())
		return fonts.find(fontName)->second.CreateText(text, scale);
	else
	{
		return nullptr;
		cerr << "Font wasn't found" << endl;
	}
}