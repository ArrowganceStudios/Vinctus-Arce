#pragma once
#include <string>
#include <vector>
#include "Button.h"
#include "Globals.h"

using namespace std;

class Button;

class Menu
{
	friend class State_Menu;

	vector<Button*> buttons; //array of pointers to distinct buttons
	Button *MarkedButton;
	string menuTitle;

public:
	Menu(string title) : menuTitle(title){ MarkedButton = NULL; };
	void AddButton(string buttonText, void(*function)());
	void Cleanup();
};