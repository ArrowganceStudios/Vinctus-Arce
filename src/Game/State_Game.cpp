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
	graphicEngine::Instance().DestroyGraphic("class GameUI_bar");

	graphicEngine::Instance().CleanUpUIMaps();
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
//	graphicEngine::Instance().RequestGraphic()
}

void State_Game::LoadResources()
{
	//Graphics
	//bars
	graphicEngine::Instance().DefineGraphic("class GameUI_bar", "assets/img/UI/button.png");

	//Sounds
}