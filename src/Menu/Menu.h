#pragma once
#include <string>
#include <vector>
#include "../Globals.h"
#include "../Graphics/UI/Image.h"

using namespace std;

class ClassSelectionIcon;
class MenuButton;
class Image;
	
class Menu : protected UIElement
{
	friend class State_Menu;
	
	vector<Image*> images;
	vector<MenuButton*> buttons; //array of pointers to distinct buttons
	vector<ClassSelectionIcon*> classIcons;
	MenuButton *MarkedButton;
	string menuTitle;

	void Polymorphic() {}

public:
	Menu(string title, float x = 400, float y = 300); //temp soultion till we fix cir.dependency
	~Menu() {};
	void AddButton(string buttonText, void(*function)());
	void AddButton(string buttonText, float x, float y, void(*function)());
	void AddImage(float x, float y, float w, float h, const int id);
	void AddClassIconBig(int classID, void(*function)());
	void Cleanup();
};