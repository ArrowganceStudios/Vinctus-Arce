#include "MenuButton.h"

MenuButton::MenuButton(string text, float x, float y, void(*function)()) : UIElement(x, y), Button(*function), text(text)
{
	width = ButtonSize::ButtonWidth;
	height = ButtonSize::ButtonHeight;

	z = 1;

	buttonText = new Text(text, "Morpheius", 0.5, x, y);

	graphicEngine::Instance().CreateUIElement_GraphicInstance(this);
}

MenuButton::~MenuButton()
{
	delete buttonText;
}