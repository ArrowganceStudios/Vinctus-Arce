#pragma once
#include <string>
#include "UI_element.h"
#include "../../Globals.h"

using namespace std;

class GraphicEngine;

class Text : protected UI_element
{
	friend class Button;
	friend class State_Menu;

	static int textID;
public:
	Text(string text, string fontName, float scale, float x, float y);
	~Text() { graphicEngine->DestroyUI_ElementGraphicInstance(this); };
};