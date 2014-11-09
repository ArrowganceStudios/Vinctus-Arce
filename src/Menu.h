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
	Menu *previousMenu; //will be changed to pointer to a function
	string menuTitle;
public:
	Menu(string title): menuTitle(title){};
	void AddButton(string buttonText, const void *function);
};