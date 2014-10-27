#pragma once
#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include "Menu.h"

class GameEngine
{
	//primitive inits
	bool done;

	//Handlers inits
	Menu *mainMenu;
	ObjectHandler *objectHandler;
	MapHandler *mapHandler;
	CameraInstance *Camera;
	CollisionDetector *Collider;
	InputHandler *Input;
	MenuInstance *mainMenu;
	LogicHandler *logicHandler;

	GraphicEngine *graphicEngine;

	//allegro inits
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *timer;
	ALLEGRO_FONT *font18;
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