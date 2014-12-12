#include "MenuButton.h"

using ::ButtonState;

void MenuButton::SetNormalState()
{
	highlighted = false;
	clicked = false;
	graphicEngine::Instance().RequestUIElement_Graphic(this, Default);

}

void MenuButton::SetHighlightedState()
{
	highlighted = true;
	graphicEngine::Instance().RequestUIElement_Graphic(this, Hover);
}

void MenuButton::SetClickedState()
{
	highlighted = false;
	clicked = true;
	graphicEngine::Instance().RequestUIElement_Graphic(this, Clicked);
}

MenuButton::MenuButton(string text, float x, float y, void(*function)()) : UIElement(x, y), Button(*function), text(text)
{
	width = ButtonSize::ButtonWidth;
	height = ButtonSize::ButtonHeight;

	z = 1;

	buttonText = new Text(text, "Morpheius", 0.5, x, y);

	graphicEngine::Instance().CreateUIElement_GraphicInstance(this);
}

void MenuButton::Hide()
{
	visible = false;
	buttonText->Hide();
}

void MenuButton::Show()
{
	visible = true;
	buttonText->Show();
}

MenuButton::~MenuButton()
{
	delete buttonText;
}