#pragma once
#include "Button.h"
#include "../Graphics/UI/Text.h"
#include "../Globals.h"
#include "../Graphics/UI/UIElement.h"

class Text;

class MenuButton : protected UIElement, public Button
{
	friend class Menu;
	friend class State_Menu;

	string text;

	Text *buttonText;
public:
	MenuButton(string text, float x, float y, void(*function)());
	~MenuButton();

	Text * GetText() const { return buttonText; }

	void Polymorphic() {};
};