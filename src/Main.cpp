#include <iostream>
#include "GameEngine.h"
#include "Globals.h"
#include "Menu/MenuActions.h"

using namespace std;

extern GameEngine *gameEngine;

int main()
{
	gameEngine->Init();

	while(gameEngine->Done())
	{
		gameEngine->InputHandler();
		gameEngine->Update();
		gameEngine->Render();
		gameEngine->Flush();
	}

	gameEngine->Destroy();
	
	return 0;
}