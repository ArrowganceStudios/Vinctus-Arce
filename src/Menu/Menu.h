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

	void Polymorphic() { cout << "I'm the best fck the rest"; }

public:
	Menu(string title, float x = 400, float y = 300); //temp soultion till we fix cir.dependency
	void AddButton(string buttonText, void(*function)());
	void Cleanup();
};