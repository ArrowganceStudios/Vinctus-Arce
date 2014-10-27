#pragma once
#include <iostream>

class GameEngine
{
	MenuInstance *mainMenu;
	ObjectHandler *objectHandler;
	MapHandler *mapHandler;
	CameraInstance *Camera;
	CollisionDetector *Collider;
	InputHandler *Input;
	MenuInstance *mainMenu;
	LogicHandler *logicHandler;

	GameLogic *gameLogic;
	GraphicEngine *graphicEngine;
public:
	GameEngine();
	~GameEngine();

	void StartGame();

	void Init();
	void Update();
	void Render();
	void Destroy();

	bool Done();
};