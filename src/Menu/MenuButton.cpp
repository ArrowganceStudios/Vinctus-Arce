#include "MenuButton.h"

using ::ButtonState;

void MenuButton::SetNormalState()
{
	highlighted = false;
	clicked = false;
	graphicEngine::Instance().RequestGraphic(this, Default);

}

void MenuButton::SetHighlightedState()
{
	highlighted = true;
	graphicEngine::Instance().RequestGraphic(this, Hover);
}

void MenuButton::SetClickedState()
{
	highlighted = false;
	clicked = true;
	graphicEngine::Instance().RequestGraphic(this, Clicked);
}

bool MenuButton::IsHighlighted()
{
	if ((mouseX >= (this->x - this->width / 2)) &&
		(mouseX <= (this->x + this->width / 2)) &&
		(mouseY >= (this->y - this->height / 2)) &&
		(mouseY <= (this->y + this->height / 2)))
	{
		if (!IsClicked()) SetHighlightedState();
		return true;
	}
	else
	{
		SetNormalState();
		return false;
	}
}

bool MenuButton::IsClicked()
{
	return clicked;
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

void MenuButton::Update()
{
	if (IsHighlighted())
	{
		if (mouse[LMB] && !IsClicked()) SetClickedState();
		if (!mouse[LMB] && IsClicked())
		{
			UseFunction();
			SetNormalState();
		}
	}
}

MenuButton::MenuButton(string text, float x, float y, void(*function)()) : UIElement(x, y), Button(*function), text(text)
{
	width = ButtonSize::ButtonWidth;
	height = ButtonSize::ButtonHeight;

	z = 1;

	buttonText = new Text(text, "Morpheius", 0.5, x, y);

	graphicEngine::Instance().CreateGraphicInstance(this);
}

MenuButton::~MenuButton()
{
	delete buttonText;
}
