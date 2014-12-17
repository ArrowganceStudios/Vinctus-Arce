#include "Text.h"

int Text::textID = 0;

Text::Text(string text, string fontName, float scale, float x, float y) : UIElement(x, y)
{
	ALLEGRO_BITMAP *textBitamp = graphicEngine::Instance().textManager->CreateText(text, fontName, scale);
	width = al_get_bitmap_width(textBitamp);
	height = al_get_bitmap_height(textBitamp);

	z = 2;

	graphicEngine::Instance().DefineGraphic("class Text", textBitamp);
	graphicEngine::Instance().CreateGraphicInstance(this);
	graphicEngine::Instance().RequestGraphic(this, textID);

	textID++;
}