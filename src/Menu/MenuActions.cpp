#include "../GameEngine.h"
#include "MenuActions.h"
//#include "../Menu/State_Menu.h"

namespace MenuActions {
	//Main menu
	void StartGame()
	{
		gameEngine->StartGame();
	}

	void CharacterSelection()
	{
		gameEngine->GetMenuState()->SwitchToMenu("Character Selection");
	}

	void Options()
	{
		gameEngine->GetMenuState()->SwitchToMenu("Options");
	}

	void Credits()
	{
		//gameEngine->GetMenuState()->SwitchToMenu("Credits");
	}

	void Exit()
	{
		gameEngine->Quit();
	}


	//Options menu
	void Resolution()
	{
		//gameEngine->GetMenuState()->SwitchToMenu("Resolution settings");
	}

	void Sound()
	{
		//gameEngine->GetMenuState()->SwitchToMenu("Sound Settings");
	}

	void Back()
	{
		gameEngine->GetMenuState()->SwitchToMenu("Main Menu");
	}


	//Surrender menu
	void Yesh()
	{
		gameEngine->GetMenuState()->SwitchToMenu("Main Menu");
	}

	void Nah()
	{
		//gameEngine->Nah();
	}


	//Wave menu
	void Continue()
	{
		gameEngine->Continue();
	}

	void Surrender()
	{
		gameEngine->GetMenuState()->SwitchToMenu("Main Menu");
	}

}