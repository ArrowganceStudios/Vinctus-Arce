#pragma once
#include "Menu.h"
#include <string>

using namespace std;

class Button
{
	int height;
	int width;

	string text;

	Menu *destinationMenu;
public:
	Button(int width, int height, string text):width(width), height(height), text(text) {};
}