#include <iostream>
#include "GameEngine.h"
using namespace std;

int main()
{
	GameEngine *engine = new GameEngine();
	engine->Init();
	while(engine->Done())
	{
		engine->Update();
		engine->Render();
	}
	engine->Destroy();
	delete engine;
	return 0;
}