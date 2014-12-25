#pragma once
#include <vector>
#include "GameUI_bar.h"
#include "../Globals.h"
#include "../Graphics/UI/UIElement.h"

class GameUI : protected UIElement
{
private:
	friend class State_Game;
	std::vector <GameUI_bar*> bars;
//	GameUI_bar *currBar;
	void ShowBars();
	void HideBars();
public:
	GameUI(float x = SCREEN_WIDTH / 2, float y = SCREEN_HEIGHT / 2) : UIElement(x, y) {  }
	~GameUI();
	void AddBar(float x, float y);
	void Cleanup();

	void Show();
	void Hide();

};