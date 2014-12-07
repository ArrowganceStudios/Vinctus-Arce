#include "Text.h"

int Text::textID = 0;

Text::Text(string text, string fontName, float scale, float x, float y) : UI_element(x, y)
{
	ALLEGRO_BITMAP *textBitamp = graphicEngine::Instance().textManager->CreateText(text, fontName, scale);
	width = al_get_bitmap_width(textBitamp);
	height = al_get_bitmap_height(textBitamp);

	z = 2;

	graphicEngine::Instance().DefineUI_Element_Graphic("class Text", textBitamp);
	graphicEngine::Instance().CreateUI_Element_GraphicInstance(this);
	graphicEngine::Instance().RequestUI_Element_Graphic(this, textID);

	textID++;
}