#pragma once
#include <vector>

using namespace std;

class Menu
{
	Button *button[]; //array of buttons, like Start Game, Credits, etc.
	Menu *previousMenu;
public:
	Menu(vector<char> title, Menu *previousMenu = NULL);
	void AddButton(vector<char> buttonText, Menu *destinationMenu);
};