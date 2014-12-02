#include "Button.h"


Button::Button(string text, float x, float y, void(*function)()) : UI_element(x, y), text(text), action(*function) 
{
	width = ButtonSize::ButtonWidth;
	height = ButtonSize::ButtonHeight;

	z = 1;

	highlighted = false;
	clicked = false;

	buttonText = new Text(text, "Morpheius", 0.5, x, y);
	
	graphicEngine->CreateUI_Element_GraphicInstance(this);
}

Button::~Button()
{
	delete buttonText;
}

//Debug methods
void Button::UseFunction()
{
	if (action != nullptr)(*action)();
}