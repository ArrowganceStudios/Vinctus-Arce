#include "ClassSelectionIcon.h"

ClassSelectionIcon::ClassSelectionIcon(float x, float y, void(*function)() = nullptr, int graphicID = 0) : UIElement(x, y), Button(*function)
{
	z = 1;
	width = ClassSelectionIconSize::IconWidth;
	height = ClassSelectionIconSize::IconHeight;

	graphicEngine::Instance().CreateGraphicInstance(this);
	graphicEngine::Instance().RequestGraphic(this, graphicID);
}