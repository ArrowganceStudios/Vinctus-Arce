#pragma once
#include "Button.h"
#include "../Graphics/UI/UIElement.h"
#include "../Globals.h"

class ClassSelectionIcon : protected UIElement, public Button
{
	friend class Menu;
	friend class State_Menu;

public:
	ClassSelectionIcon(float x, float y, void(*function)(), int graphicID);
	~ClassSelectionIcon();
	void Polymorphic() {};
};