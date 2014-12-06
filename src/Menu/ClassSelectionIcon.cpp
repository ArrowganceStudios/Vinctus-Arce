#include "ClassSelectionIcon.h"

ClassSelectionIcon::ClassSelectionIcon(float x, float y, void(*function)() = nullptr, int graphicID = 0) : UI_element(x, y), Button(*function)
{
	z = 1;
	width = ClassSelectionIconSize::IconWidth;
	height = ClassSelectionIconSize::IconHeight;

	graphicEngine->CreateUI_Element_GraphicInstance(this);
	graphicEngine->RequestUI_Element_Graphic(this, graphicID);
}