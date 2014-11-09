#include "Menu.h"
#include "Button.h"

void Menu::AddButton(string buttonText, const void *function)
{
	Button *newButton = new Button(buttonText, MenuDesign::XOffset, MenuDesign::YOffset + 
							  (buttons.size() * ((ButtonSize::height / 2) + 
							   MenuDesign::ButtonSpacing)));
	buttons.push_back(newButton);
}