#pragma once
#include <string>
#include "UIElement.h"
#include "../../Globals.h"

using namespace std;

class GraphicEngine;

class Text : protected UIElement
{
	friend class Button;
	friend class State_Menu;

	static int textID;
public:
	Text(string text, string fontName, float scale, float x, float y);
	~Text() { graphicEngine::Instance().DestroyUIElementGraphicInstance(this); };
};