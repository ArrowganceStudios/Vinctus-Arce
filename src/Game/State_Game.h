#pragma once
#include "../State.h"
#include "../Graphics/UI/UI_element.h"

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