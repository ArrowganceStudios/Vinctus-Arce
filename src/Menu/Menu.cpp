#include "Menu.h"
#include "MenuButton.h"
#include "ClassSelectionIcon.h"

Menu::Menu(string title, float x, float y) : UIElement(x, y), menuTitle(title)
{
	width = SCREEN_WIDTH;
	height = SCREEN_HEIGHT;
	z = 0;
	MarkedButton = nullptr;
	graphicEngine::Instance().CreateGraphicInstance(this);
}

void Menu::AddButton(string buttonText, void (*function)())
{
	MenuButton *newButton = new MenuButton(buttonText, MenuDesign::XOffset, MenuDesign::YOffset + 
							  (buttons.size() * ((ButtonSize::ButtonHeight / 2) + 
							   MenuDesign::ButtonSpacing)), function);
	buttons.push_back(newButton);
}

void Menu::AddButton(string buttonText, float x, float y, void(*function)())
{
	MenuButton *newButton = new MenuButton(buttonText, x, y, function);
	buttons.push_back(newButton);
}

void Menu::AddImage(float x, float y, float w, float h, const int id)
{
	Image *newImage = new Image(x, y, w, h, id);
	images.push_back(newImage);
}

void Menu::AddClassIconBig(int graphicID, void(*function)() = nullptr)
{
	float x = (SCREEN_WIDTH / 3) * (classIcons.size() + 1) - (ClassSelectionIconSize::IconWidth / 2);

	ClassSelectionIcon *newClassIcon = new ClassSelectionIcon(x, SCREEN_HEIGHT / 2, function, graphicID);
	classIcons.push_back(newClassIcon);
}

void Menu::Hide()
{
	visible = false;

	//hiding it's contents
	for (auto button : buttons)
		button->Hide();

	for (auto image : images)
		image->Hide();

	for (auto icon : classIcons)
		icon->Hide();
}

void Menu::Show()
{
	visible = true;

	//hiding it's contents
	for (auto button : buttons)
		button->Show();

	for (auto image : images)
		image->Show();

	for (auto icon : classIcons)
		icon->Show();
}

void Menu::Cleanup()
{
	for (auto button : buttons)
		graphicEngine::Instance().DestroyGraphicInstance(button);
	
	for (auto image : images)
		graphicEngine::Instance().DestroyGraphicInstance(image);

	for (auto classIcon : classIcons)
		graphicEngine::Instance().DestroyGraphicInstance(classIcon);

	graphicEngine::Instance().DestroyGraphicInstance(this);

	if (buttons.size())
		buttons.clear();
	buttons.shrink_to_fit();

	if (images.size())
		images.clear();
	images.shrink_to_fit();

	if (classIcons.size())
		classIcons.clear();
	classIcons.shrink_to_fit();
}
