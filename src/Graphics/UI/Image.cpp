#include "Image.h"

Image::Image(float x, float y, float w, float h, const int graphicId) :UI_element(x, y, h, w)
{
	z = 1;

	graphicEngine::Instance().CreateUI_Element_GraphicInstance(this);
	graphicEngine::Instance().RequestUI_Element_Graphic(this, graphicId);
}