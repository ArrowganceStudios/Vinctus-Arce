//#include "Menu.h"
#include "Button.h"

Menu::Menu(string title, float x, float y) : UI_element(x, y), menuTitle(title)
{
	width = SCREEN_WIDTH;
	height = SCREEN_HEIGHT;
	z = 0;
	MarkedButton = nullptr;
	graphicEngine->CreateUI_Element_GraphicInstance(this);
}

void Menu::AddButton(string buttonText, void (*function)())
{
	Button *newButton = new Button(buttonText, MenuDesign::XOffset, MenuDesign::YOffset + 
							  (buttons.size() * ((ButtonSize::ButtonHeight / 2) + 
							   MenuDesign::ButtonSpacing)), function);
	buttons.push_back(newButton);
}

void Menu::AddButton(string buttonText, float x, float y, void(*function)())
{
	Button *newButton = new Button(buttonText, x, y, function);
	buttons.push_back(newButton);
}

void Menu::Cleanup()
{
	this->buttons.clear();
}