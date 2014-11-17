#include "State_Game.h"
#include <vector>
#include "allegro5\allegro.h"

void State_Game::Init()
{
	ALLEGRO_BITMAP *healthBar = nullptr;
	ALLEGRO_BITMAP *energyBar = nullptr;
	ALLEGRO_BITMAP *skillsBar = nullptr;

	std::vector<ALLEGRO_BITMAP *> interFace_bitmaps { healthBar, energyBar, skillsBar };
	//graphicEngine->DefineUI_Element_Graphic("class, interface_bitmaps ")
	
}

void State_Game::Cleanup()
{

}

void State_Game::Pause()
{

}

void State_Game::Resume()
{

}

void State_Game::HandleEvents()
{

}

void State_Game::Update()
{

}

void State_Game::Render()
{

}