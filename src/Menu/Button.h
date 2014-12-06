#pragma once

using namespace std;

class Button
{
	friend class Menu;
	friend class State_Menu;

	void (*action)();
	bool highlighted;
	bool clicked;

public:
	Button(void(*function)()) : action(*function), highlighted(false), clicked(false) {};

	void UseFunction() { if (action != nullptr)(*action)(); }
};
