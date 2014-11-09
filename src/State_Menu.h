#pragma once
#include "Menu.h"
#include "State.h"
#include <vector>
#include <string>

class State_Menu: public State
{
private:
	vector<Menu *> menuList;

public:
	State_Menu();

	virtual void Init();
	void Cleanup();
	void Pause() = 0;
	void Resume() = 0;

	void HandleEvents() = 0;
	void Update() = 0;
	void Render() = 0;

};
