#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <vector>
#include "State.h"
#include "Input.h"
#include "Graphics/GraphicEngine.h"
#include "Menu/State_Menu.h"
#include "Game/State_Game.h"
#include "Menu/Menu.h"
#include "Singleton.h"


//class State;
class InputHandler;

class GameEngine : public Singleton <GameEngine>
{	
	friend class InputHandler;
	friend Singleton < GameEngine > ;
	
	//consts
	const int WIDTH = 800;  // to be changed
	const int HEIGHT = 600;
	const float FPS = 60.0f;

	//primitive inits
	bool done;
	bool render;

	//Handlers inits
	/*
	MapHandler *mapHandler;
	CameraInstance *Camera;
	CollisionDetector *Collider;
	LogicHandler *logicHandler
	*/
	InputHandler *input;

	State_Menu *menuState;
	State_Game *gameState;

	//allegro variables
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *eventQueue;
	ALLEGRO_EVENT event;
	ALLEGRO_TIMER *timer;
	//ALLEGRO_FONT *font18;

	std::vector <State*> activeStates;
	std::vector <State*> states;
protected:
	GameEngine();
	~GameEngine();
public:

	State_Menu * GetMenuState() { return menuState; }

	void StartGame();

	void Init();

	void ChangeState(State* state);
	void PushState(State* state);
	void PopState();
	
	void Escaper();
	void Update();
	void Render();
	
	void Flush();
	void Destroy();

	void Continue();
	void Quit();
	
	bool Done() const;

	ALLEGRO_EVENT_QUEUE * GetEventQueue() const { return eventQueue; }
	ALLEGRO_EVENT * GetEvent() { return &event; }
	ALLEGRO_DISPLAY * GetDisplay() { return display; }
};
