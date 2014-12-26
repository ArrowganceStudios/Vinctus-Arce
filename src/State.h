#pragma once
//#include "GameEngine.h"

class GameEngine;

class State
{
protected:
	bool isCleanedUp = 0;
	State(){}
public:
	virtual void Init() = 0;
	virtual void Cleanup() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;


	bool GetCleanedUp() { return isCleanedUp; }
};