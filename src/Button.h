#pragma once
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

public:
	Button(string text, float x, float y, void(*function)());

	void UseFunction(); //debug
};
