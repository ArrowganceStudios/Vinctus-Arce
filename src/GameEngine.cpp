#include "GameEngine.h"
#include "Menu.h"
#include "GraphicEngine.h"
#include <string>
#include <iostream>

bool GameEngine::done = false;

GameEngine::GameEngine(int w, int h, float fps):WIDTH(w), HEIGHT(h), FPS(fps) 
{
	
}

GameEngine::~GameEngine()
{
	/*delete objectHandler;
	delete mapHandler;
	delete Camera;
	delete Collider;
	delete Input;
	delete mainMenu;
	delete logicHandler;*/

	delete graphicEngine;
}

void GameEngine::Init()
{
	done = false;

	graphicEngine = new GraphicEngine();

	graphicEngine->Init();
	
	al_init(); //Initialises the allegro library
    
    display = al_create_display(WIDTH, HEIGHT);
	al_set_window_title(display, "Vinctus Arce");
    
	al_install_keyboard(); //Installs keyboard driver
    
    eventQueue = al_create_event_queue();
    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());

    timer = al_create_timer(1.0f / FPS);
    al_register_event_source(eventQueue, al_get_timer_event_source(timer));
    al_start_timer(timer);
}
void GameEngine::InputHandler()
{
	if(event.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch(event.keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			done = true;
			break;
		}
	}
	else if(event.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch(event.keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			done = true;
			break;
		}
	}
	else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		done = true;
}

void GameEngine::ChangeState(State* state) {
    // cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}
    
	// store and init the new state
	states.push_back(state);
	states.back()->Init(this);
}
void GameEngine::PushState(State* state) {
    // pause current state
	if ( !states.empty() ) {
		states.back()->Pause();
	}
    
	// store and init the new state
	states.push_back(state);
	states.back()->Init(this);
}
void GameEngine::PopState() {
    // cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}
    
	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}

void GameEngine::Update()
{
	if(event.type == ALLEGRO_EVENT_TIMER)
	{
		render = true;
	}
}
void GameEngine::Render()
{
	if(render && al_is_event_queue_empty(eventQueue))
	{
		render = false;
		
		graphicEngine->Render();

		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}
}

void GameEngine::Flush()
{
	al_wait_for_event(GetEventQueue(), GetEvent());
	al_flush_event_queue(GetEventQueue());
}

void GameEngine::Destroy()
{	
	//project objects destroy
	graphicEngine->Destroy(); //bitmaps

	//allegro vars destroy
	//al_destroy_font(font18);
	al_destroy_display(display);
	al_destroy_event_queue(eventQueue);
	al_destroy_timer(timer);
}

bool GameEngine::Done() const
{
	return !done;
};