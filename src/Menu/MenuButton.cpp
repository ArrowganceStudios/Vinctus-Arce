#include "MenuButton.h"

MenuButton::MenuButton(string text, float x, float y, void(*function)()) : UI_element(x, y), Button(*function), text(text)
{
	width = ButtonSize::ButtonWidth;
	height = ButtonSize::ButtonHeight;

	z = 1;

	buttonText = new Text(text, "Morpheius", 0.5, x, y);

	graphicEngine->CreateUI_Element_GraphicInstance(this);
}

MenuButton::~MenuButton()
{
	delete buttonText;
}