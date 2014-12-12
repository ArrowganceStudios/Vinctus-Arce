#pragma once
#include "Button.h"
#include "../Graphics/UI/Text.h"
#include "../Globals.h"
#include "../Graphics/UI/UIElement.h"

class Text;

class MenuButton : public UIElement, public Button
{
	friend class State_Menu;

	string text;

	Text *buttonText;
public:
	MenuButton(string text, float x, float y, void(*function)());
	~MenuButton();

	void SetNormalState();
	void SetHighlightedState();
	void SetClickedState();

	bool IsHighlighted() const { return highlighted; }
	bool IsClicked() const { return clicked; }

	Text * GetText() const { return buttonText; }

	void Hide();
	void Show();

	void Polymorphic() {};
};