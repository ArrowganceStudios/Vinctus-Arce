#include "Menu.h"
#include "Button.h"

void Menu::AddButton(string buttonText, void (*function)())
{
	Button *newButton = new Button(buttonText, MenuDesign::XOffset, MenuDesign::YOffset + 
							  (buttons.size() * ((ButtonSize::ButtonHeight / 2) + 
							   MenuDesign::ButtonSpacing)), function);
	buttons.push_back(newButton);
}

void Menu::Cleanup()
{
	this->buttons.clear();
}