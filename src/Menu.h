#pragma once
#include <string>
#include <vector>
#include "Button.h"

using namespace std;

class Menu
{
	vector <Button *> button; //array of pointers to distinct buttons
	Menu *previousMenu;
	string menuTitle;
public:
	Menu(string title, Menu *previousMenu = NULL): menuTitle(title){};
	void AddButton(string buttonText, Menu *destinationMenu);
};