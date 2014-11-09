#pragma once
#include "Menu.h"
#include "Globals.h"
#include <string>

using namespace std;

class Button
{
	int height;
	int width;

	float x;
	float y;

	void *function;

	string text;

	//Menu *destinationMenu;
public:
	Button(string text, float x, float y):width(ButtonSize::width), height(ButtonSize::height), x(x), y(y), text(text){};

};
