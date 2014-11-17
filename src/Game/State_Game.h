#pragma once
#include "../State.h"
#include <vector>

class GameUI;

class State_Game: public State
{
private:
	GameUI *interFace;
public:
	void Init();
	void Cleanup();
    
	void Pause();
	void Resume();
    
	void HandleEvents();
	void Update();
	void Render();
};