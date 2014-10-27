#pragma once
#include <string>
#include "Button.h"

using namespace std;

class Menu
{
	Button *button; //array
	Menu *previousMenu;
public:
	Menu(string title, Menu *previousMenu = NULL);
	void AddButton(string buttonText, Menu *destinationMenu);
};