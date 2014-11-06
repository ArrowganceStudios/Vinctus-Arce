#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Menu.h"

class GameEngine
{	
	//consts
	const int WIDTH;
	const int HEIGHT;
	const int FPS;

	//primitive inits
	bool done;
	bool render;

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

	//allegro variables
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *eventQueue;
	ALLEGRO_EVENT event;
	ALLEGRO_TIMER *timer;
	//ALLEGRO_FONT *font18;
public:
	GameEngine(int w, int h, int fps);
	~GameEngine();

	void StartGame();

	void Init();
	void InputHandler();
	void Update();
	void Render();
	void Flush();
	void Destroy();

	bool Done() const;

	ALLEGRO_EVENT_QUEUE * GetEventQueue() const { return eventQueue; }
	ALLEGRO_EVENT * GetEvent() { return &event; }
};