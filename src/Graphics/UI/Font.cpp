#include "Font.h"

using namespace std;

ALLEGRO_BITMAP* Font::Create_Text(std::string text, float scale = 1)
{
	ALLEGRO_BITMAP *output;
	int size = text.size();
	output = al_create_bitmap(scale*size*(X_CharSize + X_Offset), Y_CharSize * scale);
	al_set_target_bitmap(output);
	int k;
	bool offset = false;

	for (int i = 0; i < text.length(); i++)
	{
		if (i == 0) offset = false;
		else offset = true;
		
		k = GetCharFromTileset(text.at(i));
		
		al_draw_tinted_scaled_rotated_bitmap_region(font_set, k%columns * X_CharSize, k/columns * Y_CharSize, X_CharSize, Y_CharSize,
			al_map_rgb(255, 255, 255), 0, 0, i * X_CharSize * scale + offset * i * X_Offset * scale, 0, scale, scale, 0, 0);
	}
	return output;
}

int Font::GetCharFromTileset(char &c)
{
	switch (c)
	{
	case ' ':
		return 50;
		break;
	case 'A':
	case 'a':
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
		return 3;
		break;
	case 'E':
	case 'e':
		return 4;
		break;
	case 'F':
	case 'f':
		return 5;
		break;
	case 'G':
	case 'g':
		return 6;
		break;
	case 'H':
	case 'h':
		return 7;
	case 'I':
	case 'i':
		return 8;
		break;
	case 'J':
	case 'j':
		return 9;
		break;
	case 'K':
	case 'k':
		return 10;
		break;
	case 'L':
	case 'l':
		return 11;
		break;
	case 'M':
	case 'm':
		return 12;
		break;
	case 'N':
	case 'n':
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
		return 17;
		break;
	case 'S':
	case 's':
		return 18;
		break;
	case 'T':
	case 't':
		return 19;
	case 'U':
	case 'u':
		return 20;
		break;
	case 'V':
	case 'v':
		return 21;
		break;
	case 'W':
	case 'w':
		return 22;
		break;
	case 'X':
	case 'x':
		return 23;
		break;
	case 'Y':
	case 'y':
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