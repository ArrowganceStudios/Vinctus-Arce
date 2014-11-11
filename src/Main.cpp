#include <iostream>
#include "GameEngine.h"
#include "Globals.h"
#include "MenuActions.h"

using namespace std;

extern GameEngine *gameEngine;

int main()
{
	//GameEngine *gameEngine = new GameEngine(SCREEN_WIDTH, SCREEN_HEIGHT, 60.0f);

	gameEngine->Init();

	while(gameEngine->Done())
	{
		gameEngine->InputHandler();
		gameEngine->Update();
		gameEngine->Render();
		gameEngine->Flush();
		//MenuActions::Exit(); // <- proof that it rly works
	}

	gameEngine->Destroy();
	
	return 0;
}