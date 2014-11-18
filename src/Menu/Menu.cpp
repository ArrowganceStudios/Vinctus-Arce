#include "Menu.h"

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

void Menu::AddImage(float x, float y, float w, float h, const int id)
{
	Image *newImage = new Image(x, y, w, h, id);
	images.push_back(newImage);
}

void Menu::Cleanup()
{
	this->buttons.clear();
	buttons.shrink_to_fit();
	for (auto button : this->buttons)
		graphicEngine->DestroyUI_ElementGraphicInstance(button);
	//delete
}
