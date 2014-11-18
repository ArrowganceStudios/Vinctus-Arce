#include "Image.h"

Image::Image(float x, float y, float w, float h, const int graphicId) :UI_element(x, y, h, w)
{
	graphicEngine->CreateUI_Element_GraphicInstance(this);
	graphicEngine->RequestUI_Element_Graphic(this, graphicId);
}