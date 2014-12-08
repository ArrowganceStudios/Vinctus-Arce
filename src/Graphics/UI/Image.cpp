#include "Image.h"

Image::Image(float x, float y, float w, float h, const int graphicId) :UIElement(x, y, h, w)
{
	z = 1;

	graphicEngine::Instance().CreateUIElement_GraphicInstance(this);
	graphicEngine::Instance().RequestUIElement_Graphic(this, graphicId);
}