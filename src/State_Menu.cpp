#include "State_Menu.h"

State_Menu::State_Menu()
{
	State_Menu::Init();
}

void State_Menu::Init()
{
	Menu *mainMenu;
	Menu *optionsMenu;
	Menu *pauseMenu;
	Menu *waveMenu;
	
	mainMenu = new Menu("Main Menu");
	optionsMenu = new Menu("Options");
	pauseMenu = new Menu("Surrender?");
	waveMenu = new Menu("Next Wave");

	mainMenu->AddButton("Start Game", nullptr);
	mainMenu->AddButton("Options", nullptr);
	mainMenu->AddButton("Credits", nullptr);
	mainMenu->AddButton("Exit", nullptr);

	optionsMenu->AddButton("Resolution", nullptr);
	optionsMenu->AddButton("Sound", nullptr);
	optionsMenu->AddButton("Back", nullptr);
	
	pauseMenu->AddButton("Yesh", nullptr);
	pauseMenu->AddButton("Nah", nullptr);

	waveMenu->AddButton("Continue", nullptr);
	waveMenu->AddButton("Surrender", nullptr);


	std::vector<Menu*> menuList {mainMenu, optionsMenu, pauseMenu, waveMenu}; //C++11 Bitch
}

void State_Menu::Cleanup()
{
	//tbi
}