#include "State_Game.h"
#include "..\Globals.h"
#include "GameUI.h"
#include "allegro5\allegro.h"
#include <vector>

void State_Game::Init()
{
	interFace = new GameUI();
	interFace->AddBar();
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

void State_Game::LoadResources()
{
	//Graphics
	//bars
	ALLEGRO_BITMAP *Bar = nullptr;
	ALLEGRO_BITMAP *skillsBar = nullptr;

	std::vector<ALLEGRO_BITMAP *> bar_bitmap = { Bar };
	graphicEngine->DefineUI_Element_Graphic("class GameUI_bar", bar_bitmap);
	//Sounds
}