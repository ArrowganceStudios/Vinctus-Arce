#include "State_Game.h"
#include "..\Globals.h"
#include "GameUI.h"
#include "allegro5\allegro.h"
#include <vector>

void State_Game::Init()
{
	LoadResources();
	interFace = new GameUI();
	interFace->AddBar(BarSize::BarWidth / 2 + 20, BarSize::BarHeight / 2 + 20);
	interFace->AddBar(SCREEN_WIDTH / 2 , SCREEN_HEIGHT - 100);
	//interFace->Show();
	for (auto bar : interFace->bars) // <-----this shit is a fucking masterpiece !!
		bar->Show();
	
}

void State_Game::Cleanup()
{
	interFace->Cleanup();
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
//	graphicEngine->RequestUI_Element_Graphic()
}

void State_Game::LoadResources()
{
	//Graphics
	//bars
	ALLEGRO_BITMAP *Bar = nullptr;
	ALLEGRO_BITMAP *skillsBar = nullptr;


	Bar = al_load_bitmap("assets/img/UI/button.png");
	std::vector<ALLEGRO_BITMAP *> bar_bitmap = { Bar };
	graphicEngine->DefineUI_Element_Graphic("class GameUI_bar", bar_bitmap);
	//Sounds
}