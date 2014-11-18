#pragma once
#include "GameEngine.h"

extern GameEngine *gameEngine;
extern GraphicEngine *graphicEngine;

namespace {
	
	extern const float SCREEN_WIDTH = 800;
	extern const float SCREEN_HEIGHT = 600;

	namespace MenuDesign
	{
		const float YOffset = 200; //used for the coords of the first button
		const float XOffset = SCREEN_WIDTH / 2;
		const float ButtonSpacing = 40;
	}
	
	namespace ButtonSize
	{
		const float ButtonHeight = 66;
		const float ButtonWidth = 307;
	}

	namespace BarSize // temporary
	{
		const float BarHeight = 66;
		const float BarWidth = 307;
	}

	enum ButtonState
	{
		Default,
		Hover,
		Clicked
	};
}