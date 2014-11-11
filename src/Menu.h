#pragma once
#include <string>
#include <vector>
#include "Button.h"
#include "Globals.h"

using namespace std;

class Button;

class Menu
{
	vector<Button*> buttons; //array of pointers to distinct buttons
	string menuTitle;

public:
	Menu(string title): menuTitle(title){};
	void AddButton(string buttonText, void(*function)());
};