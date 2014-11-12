#pragma once
#include "Globals.h"
#include <string>

using namespace std;

class Button
{
	friend class Menu;
	friend class State_Menu;

	int height;
	int width;

	float x;
	float y;

	void (*action)();
	bool highlighted;
	bool clicked;

	string text;

public:
	Button(string text, float x, float y, void(*function)());

	void UseFunction(); //debug
};
