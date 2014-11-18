#pragma once
#include "UI_element.h"
#include "../../Globals.h"
//class UI_element;

class Image : protected UI_element
{
	friend class Menu;
	friend class State_Menu;

public:
	Image(float x, float y, float w, float h, const int graphicId);

	void Polymorphic() {};
};