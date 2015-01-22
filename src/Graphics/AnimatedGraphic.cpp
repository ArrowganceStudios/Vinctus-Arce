#include "AnimatedGraphic.h"
#include "../Globals.h"

float AnimatedGraphic::GetDisplayedX() const 
{ 
	return (SCREEN_WIDTH / 2 - Singleton<Camera>::Instance().GetCenterX() + GetX()); 
}

float AnimatedGraphic::GetDisplayedY() const 
{ 
	return (SCREEN_HEIGHT / 2 - Singleton<Camera>::Instance().GetCenterY() + GetY()); 
}