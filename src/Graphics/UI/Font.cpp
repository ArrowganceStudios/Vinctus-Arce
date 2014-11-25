#include "Font.h"

using namespace std;

ALLEGRO_BITMAP * Font::CreateText(string text, float scale = 1)
{
	ALLEGRO_BITMAP *output;
	int stringSize = text.size();
	bool doOffset = false;
	int valOffset = 0;
	int curOffset = 0;
	int letter;

	//int bitmapWidth = static_cast <int> (static_cast <float> (scale*stringSize*(X_CharSize + X_Offset)));
	int bitmapWidth = EvaluateOutputSize(text, scale);
	int bitmapHeight = static_cast <int> (static_cast <float> (Y_CharSize * scale));

	output = al_create_bitmap(bitmapWidth, bitmapHeight);

	al_set_target_bitmap(output);

	for (int i = 0; i < text.length(); i++)
	{
		if (i == 0) doOffset = false; //is that necessary?
		else doOffset = true;
		
		letter = GetCharFromTileset(text.at(i), valOffset);

		float sx = letter % columns * X_CharSize;
		float sy = letter / columns * Y_CharSize;
		float dx = static_cast <float> (i * X_CharSize) * scale + static_cast <float > (doOffset * i * X_Offset + curOffset) * scale;

		al_draw_tinted_scaled_rotated_bitmap_region(font_set, sx, sy, X_CharSize, Y_CharSize,
			al_map_rgb(255, 255, 255), 0, 0, dx, 0, scale, scale, 0, 0);

		curOffset += valOffset;
	}

	al_set_target_bitmap(al_get_backbuffer(gameEngine->GetDisplay()));

	return output;
}
int Font::EvaluateOutputSize(string text, float scale)
{
	int size = 0;
	int offset = 0;
	for (int i = 0; i < text.length(); i++)
	{
		size += scale * (X_CharSize + X_Offset + offset);
		int letter = GetCharFromTileset(text.at(i), offset);	//this variable is completely unused, but needed
	}
	return size - scale * X_Offset / 3;
	//return size + scale * abs(offset);
}
int Font::GetCharFromTileset(char &c, int &offset)
{
	offset = 0;
	switch (c)
	{
	case ' ':
		return 50;
		break;
	case 'A':
	case 'a':
		offset = 5;
		return 0;
		break;
	case 'B':
	case 'b':
		return 1;
		break;
	case 'C':
	case 'c':
		return 2;
		break;
	case 'D':
	case 'd':
		offset = 10;
		return 3;
		break;
	case 'E':
	case 'e':
		offset = 5;
		return 4;
		break;
	case 'F':
	case 'f':
		offset = -5;
		return 5;
		break;
	case 'G':
	case 'g':
		offset = 5;
		return 6;
		break;
	case 'H':
	case 'h':
		offset = 5;
		return 7;
	case 'I':
	case 'i':
		offset = -15;
		return 8;
		break;
	case 'J':
	case 'j':
		offset = -10;
		return 9;
		break;
	case 'K':
	case 'k':
		offset = 5;
		return 10;
		break;
	case 'L':
	case 'l':
		return 11;
		break;
	case 'M':
	case 'm':
		offset = 12;
		return 12;
		break;
	case 'N':
	case 'n':
		offset = 8;
		return 13;
		break;
	case 'O':
	case 'o':
		return 14;
		break;
	case 'P':
	case 'p':
		return 15;
		break;
	case 'Q':
	case 'q':
		return 16;
		break;
	case 'R':
	case 'r':
		offset = 5;
		return 17;
		break;
	case 'S':
	case 's':
		offset = -5;
		return 18;
		break;
	case 'T':
	case 't':
		offset = -3;
		return 19;
	case 'U':
	case 'u':
		offset = 5;
		return 20;
		break;
	case 'V':
	case 'v':
		offset = 5;
		return 21;
		break;
	case 'W':
	case 'w':
		offset = 25;
		return 22;
		break;
	case 'X':
	case 'x':
		offset = 8;
		return 23;
		break;
	case 'Y':
	case 'y':
		offset = 5;
		return 24;
		break;
	case 'Z':
	case 'z':
		return 25;
		break;
	case '1':
		return 26;
		break;
	case '2':
		return 27;
		break;
	case '3':
		return 28;
		break;
	case '4':
		return 29;
		break;
	case '5':
		return 30;
		break;
	case '6':
		return 31;
		break;
	case '7':
		return 32;
		break;
	case '8':
		return 33;
		break;
	case '9':
		return 34;
		break;
	case '0':
		return 35;
		break;
	case '-':
		return 36;
		break;
	case '+':
		return 37;
		break;
	case '(':
		return 38;
		break;
	case ')':
		return 39;
		break;
	case '!':
		return 40;
		break;
	case '&':
		return 41;
		break;
	case ':':
		return 42;
		break;
	case 39:
		return 43;
		break;
	case '"':
		return 44;
		break;
	case ',':
		return 45;
		break;
	case '.':
		return 46;
		break;
	case '?':
		return 47;
		break;
	case '/':
		return 48;
		break;
	default:
		return 50;
		break;
	}
}