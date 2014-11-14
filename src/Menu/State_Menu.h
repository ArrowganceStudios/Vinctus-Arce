#pragma once
#include <vector>
#include <string>
//#include "../State.h"
//#include "../GameEngine.h"
//#include "Menu.h"

class State;
class Menu;

class State_Menu : public State
{
private:
	vector<Menu *> menuList;

	Menu *mainMenu;
	Menu *optionsMenu;
	Menu *pauseMenu;
	Menu *waveMenu;

public:
	State_Menu(){};

	Menu *CurrentMenu;
	void SwitchToMenu(string newMenu);

	void Init();
	void Cleanup();
	void Pause();
	void Resume();

	void HandleEvents();
	void Update();
	void Render();

};
