#include "Image.h"

Image::Image(float x, float y, float w, float h, const int graphicId) :UIElement(x, y, h, w)
{
	z = 1;

	graphicEngine::Instance().CreateGraphicInstance(this);
	graphicEngine::Instance().RequestGraphic(this, graphicId);
}

Image::~Image() 
{ 
#ifdef _DEBUG
	std::cout << "Image has been succesfully deleted" << std::endl; 
#endif
}