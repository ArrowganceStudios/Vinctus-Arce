#include "GameUI_bar.h"
#include "..\Globals.h"

GameUI_bar::GameUI_bar(float x, float y) : UIElement(x, y)
{
	height = BarSize::BarHeight;
	width = BarSize::BarWidth;

	z = 1;

	graphicEngine::Instance().CreateGraphicInstance(this);
}