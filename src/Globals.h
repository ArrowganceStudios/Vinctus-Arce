#pragma once
#include "GameEngine.h"

namespace {

	extern GameEngine *gameEngine;
	extern const int SCREEN_WIDTH = 800;
	extern const int SCREEN_HEIGHT = 600;

	namespace ButtonSize
	{
		int height = 50;
		int width = 100;
	}

	namespace MenuDesign
	{
		float YOffset = 200; //used for the coords of the first button
		float XOffset = SCREEN_WIDTH / 2;
		float ButtonSpacing = 10;
	}

}