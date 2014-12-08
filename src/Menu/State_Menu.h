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
	std::vector<Menu *> menuList;

	Menu *mainMenu;
	Menu *characterSelectionMenu;
	Menu *optionsMenu;
	Menu *resolutionMenu;
	Menu *creditsMenu;
	Menu *pauseMenu;
	Menu *waveMenu;

	void LoadResources();

public:
	State_Menu(){};

	Menu *CurrentMenu;
	void SwitchToMenu(std::string newMenu);

	void Init();
	void Cleanup();
	void Pause();
	void Resume();

	void HandleEvents();
	void Update();
	void Render() {};

};
