#pragma once
#include <string>
#include "../Globals.h"
#include "../Graphics/UI/UI_element.h"

using namespace std;

class Button : protected UI_element
{
	friend class Menu;
	friend class State_Menu;

	void (*action)();
	bool highlighted;
	bool clicked;

	string text;

public:
	Button(string text, float x, float y, void(*function)());

	void UseFunction(); //debug

	void Polymorphic() {};
};
