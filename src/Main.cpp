#include <iostream>
#include "GameEngine.h"
using namespace std;

int main()
{
	GameEngine gameEngine(800, 600, 60.0f);

	gameEngine.Init();

	while(gameEngine.Done())
	{
		gameEngine.InputHandler();
		gameEngine.Update();
		gameEngine.Render();
		gameEngine.Flush();
	}

	gameEngine.Destroy();
	
	return 0;
}