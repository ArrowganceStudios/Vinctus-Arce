#include <iostream>
#include "GameEngine.h"
#include "Globals.h"
#include "Menu/MenuActions.h"

using namespace std;

int main()
{
	gameEngine::Instance().Init();

	while(gameEngine::Instance().Done())
	{
		gameEngine::Instance().Escaper();
		gameEngine::Instance().Update();
		gameEngine::Instance().Render();
		gameEngine::Instance().Flush();
	}

	gameEngine::Instance().Destroy();
	
	return 0;
}