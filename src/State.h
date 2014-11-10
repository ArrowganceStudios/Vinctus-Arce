#pragma once
#include "GameEngine.h"

class GameEngine;

class State
{
protected:
	GameEngine *engine;
	State(){}
public:
	virtual void Init(GameEngine *gameEngine) = 0;
	virtual void Cleanup() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	/*
	void ChangeState(GameEngine *game, State* state)
	{
		game->ChangeState(state);
	}*/
};