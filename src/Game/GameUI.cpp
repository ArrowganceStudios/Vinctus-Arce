#include "GameUI.h"


void GameUI::AddBar()
{
		GameUI_bar *bar = new GameUI_bar(10, 20 * bars.size());
		bars.push_back(bar);
}

void GameUI::Cleanup()
{
	this->bars.clear();
}