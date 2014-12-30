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

	bool wasClicked;
public:
	MenuButton(string text, float x, float y, void(*function)());
	~MenuButton();

	void SetNormalState();
	void SetHighlightedState();
	void SetClickedState();

	bool IsHighlighted();
	bool IsClicked() const;

	Text * GetText() const { return buttonText; }

	bool WasClicked() const  { return wasClicked; }
	void SetWasClickedToFalse() { wasClicked = false; }
	void Hide();
	void Show();

	void Update();
};