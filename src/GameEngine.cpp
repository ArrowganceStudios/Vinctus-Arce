#include "GameEngine.h"
#include "Menu.h"
#include <string>

GameEngine::GameEngine()
{
	mainMenu = new Menu("Main menu");
}

GameEngine::~GameEngine()
{
	delete objectHandler;
	delete mapHandler;
	delete Camera;
	delete Collider;
	delete Input;
	delete mainMenu;
	delete logicHandler;

	delete graphicEngine;
}

void GameEngine::Init()
{
	graphicEngine->Init();
}

void GameEngine::Update()
{
	gameLogic->Update();
}

void GameEngine::Render()
{
	graphicEngine->Render();
}

void GameEngine::Destroy()
{
	gameLogic->Destroy(); //some shits
	graphicEngine->Destroy(); //bitmaps
}

void GameEngine::StartGame()
{
	objectHandler = new ObjectHandler();
	mapHandler = new MapHandler();
	Camera = new CameraInstance();
	Collider = new CollisionDetector();
	Input = new InputHandler();
	mainMenu = new MenuInstance();
	logicHandler = new LogicHandler();
}

bool GameEngine::Done()
{
	return done;
}