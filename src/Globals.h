#pragma once
#include "GameEngine.h"

extern GameEngine *gameEngine;
extern GraphicEngine *graphicEngine;

namespace {
	
	extern const int SCREEN_WIDTH = 800;
	extern const int SCREEN_HEIGHT = 600;

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
}