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
	for (auto button : buttons)
		graphicEngine->DestroyUI_ElementGraphicInstance(button);
	
	for (auto image : images)
		graphicEngine->DestroyUI_ElementGraphicInstance(image);

	graphicEngine->DestroyUI_ElementGraphicInstance(this);

	if (buttons.size())
		buttons.clear();
		buttons.shrink_to_fit();

	if (images.size())
		images.clear();
		images.shrink_to_fit();

	//delete
}
