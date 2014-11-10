#pragma once
#include "State.h"

class State_Game: public State
{
public:
	void Init(GameEngine *engine);
	void Cleanup();
    
	void Pause();
	void Resume();
    
	void HandleEvents(GameEngine* gameEngine);
	void Update(GameEngine* gameEngine);
	void Render(GameEngine* gameEngine);
};