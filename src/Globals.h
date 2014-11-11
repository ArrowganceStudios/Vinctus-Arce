#pragma once
#include "GameEngine.h"

extern GameEngine *gameEngine;

namespace {
	
	extern const int SCREEN_WIDTH = 800;
	extern const int SCREEN_HEIGHT = 600;

	namespace MenuDesign
	{
		float YOffset = 200; //used for the coords of the first button
		float XOffset = SCREEN_WIDTH / 2;
		float ButtonSpacing = 10;
	}
	
	namespace ButtonSize
	{
		int ButtonHeight = 50;
		int ButtonWidth = 100;
	}
}