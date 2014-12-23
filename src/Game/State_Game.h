#pragma once
#include "../State.h"
#include "Scene\Layers\MapLayer.h"
#include "Scene\Layer.h"
#include <vector>

class GameUI;

class State_Game: public State
{
private:
	GameUI *interFace;

	std::vector<Layer*> GameScene;

	MapLayer *myLevel;

	void State_Game::LoadResources();

public:
	void Init();
	void Cleanup();
    
	void Pause();
	void Resume();
    
	void HandleEvents();
	void Update();
	void Render() {};
};