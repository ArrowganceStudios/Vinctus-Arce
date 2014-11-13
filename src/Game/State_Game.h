#pragma once
#include "../State.h"

class State_Game: public State
{
public:
	void Init();
	void Cleanup();
    
	void Pause();
	void Resume();
    
	void HandleEvents();
	void Update();
	void Render();
};