
#include <iostream>
#include "GameEngine.h"
#include "Globals.h"
#include "Menu/MenuActions.h"
#include <vld.h>

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
	
	cin.get();
	return 0;
}