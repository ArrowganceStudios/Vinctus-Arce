#include "GameUI_bar.h"
#include "..\Globals.h"

GameUI_bar::GameUI_bar(float x, float y) : UI_element(x, y)
{
	height = BarSize::BarHeight;
	width = BarSize::BarWidth;

	z = 1;

	graphicEngine->CreateUI_Element_GraphicInstance(this);
}