#pragma once
#include "src\Ga

class State
{
public:
	virtual void Init();
	virtual void Clear();
	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents();
	virtual void Update();
	virtual void Render();
protected:
	State(){}
};