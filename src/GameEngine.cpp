#include <string>
#include <iostream>
#include "GameEngine.h"
#include "Input.h"
#include "Menu/Menu.h"
#include "Graphics/GraphicEngine.h"
#include "Game/State_Game.h"

GameEngine::GameEngine()
{

}

/*GameEngine::~GameEngine()
{

	delete mapHandler;
	delete Camera;
	delete Collider;
	delete mainMenu;  // i don't think it will be needed
	delete logicHandler;

	delete gameState;
	delete menuState;
	delete input;
}*/

void GameEngine::Init()
{
	done = false;

	input = new InputHandler();

	menuState = new State_Menu();
	gameState = new State_Game();

	states.push_back(menuState);
	states.push_back(gameState);

	graphicEngine::Instance().Init();
	input->Init();

	al_init(); //Initialises the allegro library
	al_install_keyboard();
	al_install_mouse();
	
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_SUGGEST);
	al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR);
	al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
	al_set_new_display_option(ALLEGRO_SAMPLES, 6, ALLEGRO_SUGGEST);

    display = al_create_display(WIDTH, HEIGHT);
	al_set_window_title(display, "Vinctus Arce");
    
    eventQueue = al_create_event_queue();
    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_mouse_event_source());

    timer = al_create_timer(1.0f / FPS);
    al_register_event_source(eventQueue, al_get_timer_event_source(timer));
    al_start_timer(timer);

	PushState(menuState);
}

void GameEngine::StartGame()
{
	ChangeState(gameState);

}

void GameEngine::Continue()
{
	PopState();
}

void GameEngine::Escaper() //this should be done in seperate class if I'm correct?
{
	if(event.type == ALLEGRO_EVENT_KEY_DOWN) /////// do we need this?
	{
		switch(event.keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			Quit();
			break;
		}
	}
	else if (event.type == ALLEGRO_EVENT_KEY_UP) //I'd rather ask whether we need that
	{
		switch (event.keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
			Quit();
			break;
		}
	}
	else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		Quit();
}

void GameEngine::ChangeState(State* state) {
    // cleanup the current state
	if (!activeStates.empty()) {
		activeStates.back()->Cleanup();
		activeStates.pop_back();
	}
    
	// store and init the new state
	activeStates.push_back(state);
	activeStates.back()->Init();
}

void GameEngine::PushState(State* state) {
    // pause current state
	if (!activeStates.empty()) {
		activeStates.back()->Pause();
	}
    
	// store and init the new state
	activeStates.push_back(state);
	activeStates.back()->Init();
}

void GameEngine::PopState() {
    // cleanup the current state
	if (!activeStates.empty()) {
		activeStates.back()->Cleanup();
		activeStates.pop_back();
	}
    
	// resume previous state
	if (!activeStates.empty()) {
		activeStates.back()->Resume();
	}
}

void GameEngine::Update()
{
	input->Update(&event);
	activeStates.back()->Update();
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
		
		graphicEngine::Instance().Render();

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
	
	for (auto state : states)
	{
		if (!state->GetCleanedUp())
		{
			state->Cleanup();
		}
		delete state;
	}

	states.clear();
	states.shrink_to_fit();
	activeStates.clear();
	activeStates.shrink_to_fit();
	
	
	delete input;

	graphicEngine::Instance().Destroy(); //bitmap
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

void GameEngine::Quit()
{
	done = true;
}