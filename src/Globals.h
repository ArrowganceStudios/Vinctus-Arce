#pragma once
#include "GameEngine.h"
#include "Graphics/GraphicEngine.h"
#include "Singleton.h"
#include "Game/ObjectHandler.h"


typedef Singleton<GameEngine> gameEngine;
typedef Singleton<GraphicEngine> graphicEngine;
typedef Singleton<ObjectHandler> objectHandler; 

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

	namespace ClassSelectionIconSize
	{
		const float IconHeight = 265;
		const float IconWidth = 263;
	}

	namespace BarSize // temporary
	{
		const float BarHeight = 66;
		const float BarWidth = 307;
	}

	namespace TileSize // temporary
	{
		const float tileHeight = 80;
		const float tileWidth = 60;
	}

	namespace SliderDimension
	{
		const float sliderBarWidth = 243;
		const float sliderBarHeight = 13;
		const float sliderWidth = 30;
		const float sliderHeight = 70;
	}

	enum ClassID
	{
		Warrior,
		Ranger,
		Mage
	};

	enum ClassIconGraphic
	{
		Disabled,
		WarriorNormal,
		WarriorHovered,
		WarriorClicked,
		RangerNormal,
		RangerHovered,
		RangerClicked,
		MageNormal,
		MageHovered,
		MageClicked
	};

	enum ButtonState
	{
		Default,
		Hover,
		Clicked
	};
}

