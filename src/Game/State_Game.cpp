#include "State_Game.h"
#include "..\Globals.h"
#include "GameUI.h"
#include "allegro5\allegro.h"
#include <vector>

void State_Game::Init()
{
	LoadResources();

	isCleanedUp = false;

	myLevel = new MapLayer();
	GameScene.push_back(myLevel);
	myLevel->Init("assets/img/map.png", "assets/img/mapTileset.png");
	
	interFace = new GameUI();

	interFace->AddBar(BarSize::BarWidth / 2 + 20, BarSize::BarHeight / 2 + 20);
	interFace->AddBar(SCREEN_WIDTH / 2 , SCREEN_HEIGHT - 100);

	interFace->Show();

	interFace->Hide();
}

void State_Game::Cleanup()
{
	graphicEngine::Instance().DestroyGraphic("class GameUI_bar");

	graphicEngine::Instance().CleanUpUIMaps();

	delete interFace;
	delete myLevel;

	GameScene.clear();
	GameScene.shrink_to_fit();

	isCleanedUp = true;
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