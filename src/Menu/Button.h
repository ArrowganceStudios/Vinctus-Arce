#pragma once
#include <string>
#include "../Globals.h"
#include "../Graphics/UI/UI_element.h"
#include "../Graphics/UI/Text.h"

using namespace std;

class Text;

class Button : protected UI_element
{
	friend class Menu;
	friend class State_Menu;

	void (*action)();
	bool highlighted;
	bool clicked;

	string text;

	Text *buttonText;

public:
	Button(string text, float x, float y, void(*function)());
	~Button();

	Text * GetText() const { return buttonText; }

	void UseFunction(); //debug

	void Polymorphic() {};
};
