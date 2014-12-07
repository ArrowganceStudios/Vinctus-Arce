#include "Font.h"

using namespace std;
ALLEGRO_BITMAP * Font::CreateText(string text, float scale = 1)
{
	ALLEGRO_BITMAP *output;
	int stringSize = text.size();
	bool doOffset = true;
	int valOffset = 0;
	int curOffset = 0;
	int letter;

	int bitmapWidth =  EvaluateOutputSize(text, scale);
	int bitmapHeight = static_cast <int> (static_cast <float> (Y_CharSize * scale));

	output = al_create_bitmap(bitmapWidth, bitmapHeight);

	al_set_target_bitmap(output);

	for (unsigned char i = 0; i < text.length(); i++)
	{
		letter = GetCharFromTileset(text.at(i));
		valOffset = GetOffsetFromTileset(text.at(i));

		float sx = letter % columns * X_CharSize;
		float sy = letter / columns * Y_CharSize;
		float dx = static_cast <float> (i * X_CharSize) * scale + static_cast <float> (doOffset * i * X_Offset + curOffset) * scale;

		al_draw_tinted_scaled_rotated_bitmap_region(font_set, sx, sy, X_CharSize, Y_CharSize,
			al_map_rgb(255, 255, 255), 0, 0, dx, 0, scale, scale, 0, 0);

		curOffset += valOffset;
	}

	al_set_target_bitmap(al_get_backbuffer(gameEngine::Instance().GetDisplay()));

	return output;
}
void Font::InitializeAlphabet(std::map<char, std::pair<int, int>> &alphabet)
{
	alphabet.emplace(' ', make_pair(50, 0));
	alphabet.emplace('A', make_pair(0, 5));
	alphabet.emplace('a', make_pair(0, 5));
	alphabet.emplace('B', make_pair(1, 0));
	alphabet.emplace('b', make_pair(1, 0));
	alphabet.emplace('C', make_pair(2, 0));
	alphabet.emplace('c', make_pair(2, 0));
	alphabet.emplace('D', make_pair(3, 10));
	alphabet.emplace('d', make_pair(3, 10));
	alphabet.emplace('E', make_pair(4, 5));
	alphabet.emplace('e', make_pair(4, 5));
	alphabet.emplace('F', make_pair(5, -5));
	alphabet.emplace('f', make_pair(5, -5));
	alphabet.emplace('G', make_pair(6, 5));
	alphabet.emplace('g', make_pair(6, 5));
	alphabet.emplace('H', make_pair(7, 5));
	alphabet.emplace('h', make_pair(7, 5));
	alphabet.emplace('I', make_pair(8, -15));
	alphabet.emplace('i', make_pair(8, -15));
	alphabet.emplace('J', make_pair(9, -10));
	alphabet.emplace('j', make_pair(9, -10));
	alphabet.emplace('K', make_pair(10, -10));
	alphabet.emplace('k', make_pair(10, -10));
	alphabet.emplace('L', make_pair(11, 0));
	alphabet.emplace('l', make_pair(11, 0));
	alphabet.emplace('M', make_pair(12, 12));
	alphabet.emplace('m', make_pair(12, 12));
	alphabet.emplace('N', make_pair(13, 8));
	alphabet.emplace('n', make_pair(13, 8));
	alphabet.emplace('O', make_pair(14, 0));
	alphabet.emplace('o', make_pair(14, 0));
	alphabet.emplace('P', make_pair(15, 0));
	alphabet.emplace('p', make_pair(15, 0));
	alphabet.emplace('Q', make_pair(16, 0));
	alphabet.emplace('q', make_pair(16, 0));
	alphabet.emplace('R', make_pair(17, 5));
	alphabet.emplace('r', make_pair(17, 5));
	alphabet.emplace('S', make_pair(18, -5));
	alphabet.emplace('s', make_pair(18, -5));
	alphabet.emplace('T', make_pair(19, -3));
	alphabet.emplace('t', make_pair(19, -3));
	alphabet.emplace('U', make_pair(20, 5));
	alphabet.emplace('u', make_pair(20, 5));
	alphabet.emplace('V', make_pair(21, 5));
	alphabet.emplace('v', make_pair(21, 5));
	alphabet.emplace('W', make_pair(22, 25));
	alphabet.emplace('w', make_pair(22, 25));
	alphabet.emplace('X', make_pair(23, 8));
	alphabet.emplace('x', make_pair(23, 8));
	alphabet.emplace('Y', make_pair(24, 5));
	alphabet.emplace('y', make_pair(24, 5));
	alphabet.emplace('Z', make_pair(25, 0));
	alphabet.emplace('z', make_pair(25, 0));

	alphabet.emplace('1', make_pair(26, 0));
	alphabet.emplace('2', make_pair(27, 0));
	alphabet.emplace('3', make_pair(28, 0));
	alphabet.emplace('4', make_pair(29, 0));
	alphabet.emplace('5', make_pair(30, 0));
	alphabet.emplace('6', make_pair(31, 0));
	alphabet.emplace('7', make_pair(32, 0));
	alphabet.emplace('8', make_pair(33, 0));
	alphabet.emplace('9', make_pair(34, 0));
	alphabet.emplace('0', make_pair(35, 0));
	alphabet.emplace('-', make_pair(36, 0));
	alphabet.emplace('+', make_pair(37, 0));
	alphabet.emplace('(', make_pair(38, 0));
	alphabet.emplace(')', make_pair(39, 0));
	alphabet.emplace('!', make_pair(40, 0));
	alphabet.emplace('&', make_pair(41, 0));
	alphabet.emplace(':', make_pair(42, 0));
	alphabet.emplace('\'', make_pair(43, 0));
	alphabet.emplace('"', make_pair(44, 0));
	alphabet.emplace(',', make_pair(45, 0));
	alphabet.emplace('.', make_pair(46, 0));
	alphabet.emplace('?', make_pair(47, 0));
	alphabet.emplace('/', make_pair(48, 0));

}
int Font::EvaluateOutputSize(string text, float scale)
{
	int size = 0;
	int offset = 0;
	for (unsigned char i = 0; i < text.length(); i++)
	{
		size += scale * (X_CharSize + X_Offset + offset);
		offset = GetOffsetFromTileset(text.at(i));
	}
	return size - scale * X_Offset/1.5;
}
int Font::GetCharFromTileset(char &c)
{
	return alphabet[c].first;
}
int Font::GetOffsetFromTileset(char &c)
{
	return alphabet[c].second;
}