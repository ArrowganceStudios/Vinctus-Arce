#include "ClassSelectionIcon.h"

ClassSelectionIcon::ClassSelectionIcon(float x, float y, void(*function)() = nullptr, int graphicID = 0) : UIElement(x, y), Button(*function)
{
	z = 1;
	width = ClassSelectionIconSize::IconWidth;
	height = ClassSelectionIconSize::IconHeight;

	graphicEngine::Instance().CreateUIElement_GraphicInstance(this);
	graphicEngine::Instance().RequestUIElement_Graphic(this, graphicID);
}