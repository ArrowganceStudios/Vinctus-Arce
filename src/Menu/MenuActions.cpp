#include "../GameEngine.h"
#include "MenuActions.h"

namespace MenuActions {
	//Main menu
	void StartGame()
	{
		gameEngine::Instance().StartGame();
	}

	void CharacterSelection()
	{
		gameEngine::Instance().GetMenuState()->SwitchToMenu("Character Selection");
	}

	void Options()
	{
		gameEngine::Instance().GetMenuState()->SwitchToMenu("Options");
	}

	void Credits()
	{
		gameEngine::Instance().GetMenuState()->SwitchToMenu("Credits");
	}

	void Exit()
	{
		gameEngine::Instance().Quit();
	}

	//Options menu
	void Resolution()
	{
		gameEngine::Instance().GetMenuState()->SwitchToMenu("Resolution Settings");
	}

	void Sound()
	{
		//gameEngine::Instance().GetMenuState()->SwitchToMenu("Sound Settings");
	}
	
	void Back()
	{
		gameEngine::Instance().GetMenuState()->SwitchToMenu("Main Menu");
	}




	//Surrender menu
	void Yesh()
	{
		gameEngine::Instance().GetMenuState()->SwitchToMenu("Main Menu");
	}

	void Nah()
	{
		//gameEngine::Instance().Nah();
	}


	//Wave menu
	void Continue()
	{
		gameEngine::Instance().Continue();
	}

	void Surrender()
	{
		gameEngine::Instance().PopState(); //deleting the wave menu state
		gameEngine::Instance().ChangeState(gameEngine::Instance().GetMenuState()); //switching from gameState to menuState
	}

}