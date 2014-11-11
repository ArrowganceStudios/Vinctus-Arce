#include "MenuActions.h"
#include "GameEngine.h"
//#include "Globals.h"

//extern GameEngine *gameEngine;

namespace MenuActions {
	//Main menu
	void StartGame()
	{
		//gameEngine->ChangeState(new State_Game);
	}

	void Options()
	{
		//gameEngine->ChangeState(new State_Menu); //wtf idk
	}

	void Credits()
	{
		//gameEngine->ChangeState(new State_Menu);
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