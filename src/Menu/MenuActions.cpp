#include "../GameEngine.h"
#include "MenuActions.h"

namespace MenuActions {
	//Main menu
	void StartGame()
	{
		gameEngine->StartGame();
	}

	void Options()
	{
		//gameEngine->ChangeState(new Options); //wtf idk
	}

	void Credits()
	{
		//gameEngine->ChangeState(new Credits);
	}

	void Exit()
	{
		gameEngine->Quit();
	}


	//Options menu
	void Resolution()
	{
		//gameEngine->ChangeState(new State_Menu);
	}

	void Sound()
	{
		//gameEngine->ChangeState(new State_Menu);
	}

	void Back()
	{
		//gameEngine->ChangeState(new State_Menu);
	}


	//Surrender menu
	void Yesh()
	{
		//gameEngine->Yes();
	}

	void Nah()
	{
		//gameEngine->Nah();
	}


	//Wave menu
	void Continue()
	{
		//gameEngine->Continue();
	}

	void Surrender()
	{
		//gameEngine->ChangeState(new State_Menu);
	}

}