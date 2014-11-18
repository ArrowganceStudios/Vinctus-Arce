#pragma once
#include <vector>
#include "GameUI_bar.h"
#include "../Globals.h"
#include "../Graphics/UI/UI_element.h"

class GameUI : protected UI_element
{
private:
	friend class State_Game;
	std::vector <GameUI_bar*> bars;
//	GameUI_bar *currBar;
public:
	GameUI(float x = 400, float y = 300) : UI_element(x, y) {  }
	void AddBar(float x, float y);
	void Cleanup();

};