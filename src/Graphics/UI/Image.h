#pragma once
#include "UIElement.h"
#include "../../Globals.h"
//class UIElement;

class Image : protected UIElement
{
	friend class Menu;
	friend class State_Menu;

public:
	Image(float x, float y, float w, float h, const int graphicId);

	void Polymorphic() {};
};