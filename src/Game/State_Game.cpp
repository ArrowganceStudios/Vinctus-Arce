#include "State_Game.h"
#include "../Globals.h"
#include "GameUI.h"
#include "allegro5/allegro.h"
#include <vector>
#include <ctime>
#include <stdio.h>
#include "Yeti.h"

void State_Game::Init()
{
	LoadResources();

	srand(time(NULL));

	isCleanedUp = false;

	myLevel = new MapLayer();
	GameScene.push_back(myLevel);
	myLevel->Init("assets/img/map.png", "assets/img/mapTileset.png");

	interFace = new GameUI();

	interFace->AddBar(BarSize::BarWidth / 2 + 20, BarSize::BarHeight / 2 + 20);
	interFace->AddBar(SCREEN_WIDTH / 2 , SCREEN_HEIGHT - 100);
	
	ObjectHandler::Instance().CreateObject<class Player>(600, 600);

	interFace->Show();

	interFace->Hide();
}

void State_Game::Cleanup()
{
	graphicEngine::Instance().DestroyGraphic("class GameUI_bar");

	graphicEngine::Instance().CleanUpUIMaps();

	objectHandler::Instance().CleanUp();

	gameEngine::Instance().GetCollisionDetector()->Cleanup();

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
	objectHandler::Instance().Update();
	camera::Instance().CalculateCamera();
	camera::Instance().Update();

	//GenerateNPCs(); //disabled for now, for the sake of testing collisions
}

void State_Game::GenerateNPCs()
{
	if (objectHandler::Instance().GetNPCNumber() <= 10)
	{
		int random = rand() % 4 + 1;

		float topLeftX = camera::Instance().GetTopLeftCornerX();
		float topLeftY = camera::Instance().GetTopLeftCornerY();

		float bottomRightX = camera::Instance().GetBottomRightCornerX();
		float bottomRightY = camera::Instance().GetBottomRightCornerY();

		switch (random)
		{
		case 1:
			objectHandler::Instance().CreateObject<Yeti>(topLeftX - 32, rand() % (int)bottomRightY + (bottomRightY - SCREEN_HEIGHT / 2));
			break;
		case 2:
			objectHandler::Instance().CreateObject<Yeti>(bottomRightX + 32, rand() % (int)bottomRightY + (bottomRightY - SCREEN_HEIGHT / 2));
			break;
		case 3:
			objectHandler::Instance().CreateObject<Yeti>(rand() % (int)bottomRightX + (bottomRightY - SCREEN_WIDTH / 2), topLeftY - 32);
			break;
		default:
			objectHandler::Instance().CreateObject<Yeti>(rand() % (int)bottomRightX + (bottomRightY - SCREEN_WIDTH / 2), bottomRightY + 32);
			break;
		}
	}
}

void State_Game::LoadResources()
{
	//Graphics
	//Sprite *heroSprite = new Sprite(16, 0, 0, 5, 64, 64, 4, al_load_bitmap("assets/img/custom_hero.png"));
	
	Sprite *heroGoUp = new Sprite(3, 0, 4, 5, 64, 64, 4, al_load_bitmap("assets/img/hero_walk_up.png"));
	Sprite *heroGoDown = new Sprite(3, 0, 4, 5, 64, 64, 4, al_load_bitmap("assets/img/hero_walk_down.png"));
	Sprite *heroGoLeft = new Sprite(3, 0, 4, 5, 64, 64, 4, al_load_bitmap("assets/img/hero_walk_left.png"));
	Sprite *heroGoRight = new Sprite(3, 0, 4, 5, 64, 64, 4, al_load_bitmap("assets/img/hero_walk_right.png"));


	//graphicEngine::Instance().DefineAnimation("class Player", heroSprite);

	graphicEngine::Instance().DefineAnimation("class Player", heroGoUp);
	graphicEngine::Instance().DefineAnimation("class Player", heroGoDown);
	graphicEngine::Instance().DefineAnimation("class Player", heroGoLeft);
	graphicEngine::Instance().DefineAnimation("class Player", heroGoRight);

	//bars
	graphicEngine::Instance().DefineGraphic("class GameUI_bar", "assets/img/UI/button.png");

	//Sounds
}