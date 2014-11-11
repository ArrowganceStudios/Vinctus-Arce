#pragma once
//#include "Menu.h"
#include "Globals.h"
#include <string>

using namespace std;

class Button
{
	int height;
	int width;

	float x;
	float y;

	void (*action)();

	string text;

	//Menu *destinationMenu;
public:
	Button(string text, float x, float y, void (*function)()):width(ButtonSize::ButtonWidth), height(ButtonSize::ButtonHeight), x(x), y(y), text(text), action(*function) {};

	//void UseFunction();
};
