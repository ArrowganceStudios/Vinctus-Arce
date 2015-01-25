#pragma once
#include "../State.h"
#include "Scene\Layers\MapLayer.h"
#include "Scene\Layer.h"
#include <vector>
#include "Player.h"
#include "Scene\Camera.h"

class GameUI;

class State_Game: public State
{
private:
	GameUI *interFace;

	std::vector<Layer*> GameScene;

	MapLayer *myLevel;

	Player *player;

	void State_Game::LoadResources();

public:
	//	~State_Game();
	void Init();
	void Cleanup();
    
	void Pause();
	void Resume();
    
	void HandleEvents();
	void Update();
	void Render() {};

	void GenerateNPCs();

	MapLayer* GetMapLayer() const { return myLevel; }
};