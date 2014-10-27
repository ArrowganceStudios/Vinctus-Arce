#pragma once
#include <iostream>
#include "Menu.h"

class GameEngine
{
	bool done;

	Menu *mainMenu;
	ObjectHandler *objectHandler;
	MapHandler *mapHandler;
	CameraInstance *Camera;
	CollisionDetector *Collider;
	InputHandler *Input;
	MenuInstance *mainMenu;
	LogicHandler *logicHandler;

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