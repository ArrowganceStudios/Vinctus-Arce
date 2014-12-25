#include "GameUI.h"


GameUI::~GameUI()
{
	Cleanup();
}

void GameUI::AddBar(float x, float y)
{
		GameUI_bar *bar = new GameUI_bar(x, y);
		bars.push_back(bar);
}

void GameUI::Cleanup()
{
	for (auto bar : bars)
		if (bar != nullptr)
			delete bar;

	if (bars.size())
		bars.clear();
	bars.shrink_to_fit();
}

void GameUI::Show()
{
	ShowBars();
}

void GameUI::Hide()
{
	HideBars();
}

void GameUI::ShowBars()
{
	for (auto bar : bars)
		bar->Show();
}

void GameUI::HideBars()
{
	for (auto bar : bars)
		bar->Hide();
}
