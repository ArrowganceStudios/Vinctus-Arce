#pragma once
#include "Button.h"
#include "../Graphics/UI/UI_element.h"
#include "../Globals.h"

class ClassSelectionIcon : protected UI_element, public Button
{
	friend class Menu;
	friend class State_Menu;

public:
	ClassSelectionIcon(float x, float y, void(*function)(), int graphicID);
	void Polymorphic() {};
};