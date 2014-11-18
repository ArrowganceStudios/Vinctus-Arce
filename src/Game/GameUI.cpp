#include "GameUI.h"


void GameUI::AddBar(float x, float y)
{
		GameUI_bar *bar = new GameUI_bar(x, y);
		bars.push_back(bar);
}

void GameUI::Cleanup()
{
	this->bars.clear();
	bars.shrink_to_fit();
}