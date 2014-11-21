#pragma once
#include <string>
#include <vector>
#include "../Globals.h"
#include "Button.h"
#include "../Graphics/UI/Image.h"

using namespace std;

class Button;
class Image;
	
class Menu : protected UI_element
{
	friend class State_Menu;
	
	vector<Image*> images;
	vector<Button*> buttons; //array of pointers to distinct buttons
	Button *MarkedButton;
	string menuTitle;

	void Polymorphic() { cout << "I'm the best fck the rest"; }

public:
	Menu(string title, float x = 400, float y = 300); //temp soultion till we fix cir.dependency
	~Menu() {};
	void AddButton(string buttonText, void(*function)());
	void AddButton(string buttonText, float x, float y, void(*function)());
	void AddImage(float x, float y, float w, float h, const int id);
	void Cleanup();
};