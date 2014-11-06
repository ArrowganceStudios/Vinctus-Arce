#pragma once
#include "GameEngine.h"

class State
{
public:
	virtual void Init() = 0;
	virtual void Clear() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	void ChangeState(GameEngine* game, State* state)
	{
		game->ChangeState(state);
	}
protected:
	State(){}
};