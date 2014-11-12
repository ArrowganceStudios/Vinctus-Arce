#pragma once
#include "Menu.h"
#include "State.h"
#include "GameEngine.h"
#include <vector>
#include <string>

class State_Menu: public State
{
private:
	vector<Menu *> menuList;  
	
public:
	State_Menu();

	void Init();
	void Cleanup();
	void Pause();
	void Resume();

	void HandleEvents();
	void Update();
	void Render();

};
