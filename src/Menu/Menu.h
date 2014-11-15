#pragma once
#include <string>
#include <vector>
#include "../Globals.h"
#include "Button.h"

using namespace std;

class Button;

class Menu : protected UI_element
{
	friend class State_Menu;

	vector<Button*> buttons; //array of pointers to distinct buttons
	Button *MarkedButton;
	string menuTitle;

public:
	Menu(string title, float x = SCREEN_WIDTH/2, float y = SCREEN_HEIGHT/2);
	void AddButton(string buttonText, void(*function)());
	void Cleanup();
};