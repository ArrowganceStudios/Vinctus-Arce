#include "../Globals.h"
#include "../GameEngine.h"
#include "../Graphics/GraphicEngine.h"
#include "State_Menu.h"
#include "MenuActions.h"

void State_Menu::Init()
{	
	mainMenu = new Menu("Main Menu");
	optionsMenu = new Menu("Options");
	pauseMenu = new Menu("Surrender?");
	waveMenu = new Menu("Next Wave");

	mainMenu->AddButton("Start Game", MenuActions::StartGame);
	mainMenu->AddButton("Options", MenuActions::Options);
	mainMenu->AddButton("Credits", MenuActions::Credits);
	mainMenu->AddButton("Exit", MenuActions::Exit);

	optionsMenu->AddButton("Resolution", MenuActions::Resolution);
	optionsMenu->AddButton("Sound", MenuActions::Sound);
	optionsMenu->AddButton("Back", MenuActions::Back);
	
	pauseMenu->AddButton("Yesh", MenuActions::Yesh);
	pauseMenu->AddButton("Nah", MenuActions::Nah);

	waveMenu->AddButton("Continue", MenuActions::Continue);
	waveMenu->AddButton("Surrender", MenuActions::Surrender);


	menuList = {mainMenu, optionsMenu, pauseMenu, waveMenu}; //C++11 Bitch
	SwitchToMenu(MAIN);
}

void State_Menu::SwitchToMenu(int choice)
{
	switch (choice)
	{

	case MAIN:
		Current = this->mainMenu;
		break;
	case OPTIONS:
		Current = this->optionsMenu;
		break;
	case PAUSE:
		Current = this->pauseMenu;
		break;
	case WAVE:
		Current = this->waveMenu;
		break;
	default:
		Current = this->mainMenu;
		break;
	}

}

void State_Menu::Cleanup()
{
	while (!menuList.empty())
	{
		menuList.back()->Cleanup();
		menuList.pop_back();
	}
}

void State_Menu::Pause()
{
	//???
}
void State_Menu::Resume()
{
	//???
}

void State_Menu::HandleEvents()
{

}

void State_Menu::Update()		//	To do: handling input/UseFunction();
{
	/*
	for (int i = 0; i < Current->buttons.size(); i++)
	{
		if ((myEngine->mouseX >= (Current->buttons[i]->x - Current->buttons[i]->width / 2)) &&
			(myEngine->mouseX <= (Current->buttons[i]->x + Current->buttons[i]->width / 2)) &&
			(myEngine->mouseY >= (Current->buttons[i]->y - Current->buttons[i]->height / 2)) &&
			(myEngine->mouseY <= (Current->buttons[i]->y + Current->buttons[i]->height / 2)))
		{
			Current->buttons[i]->highlighted = true;
			if (Current->MarkedButton == NULL) Current->MarkedButton = Current->buttons[i];
			break;
		}
		else
		{
			Current->buttons[i]->highlighted = false;
			if (Current->MarkedButton != NULL) Current->MarkedButton = NULL;
			if (Current->buttons[i]->clicked) Current->buttons[i]->clicked = false;
		}
	}
	if (myEngine->mouseLMB)
	{
		if (Current->MarkedButton != NULL && Current->MarkedButton->highlighted) Current->MarkedButton->clicked = true;
	}
	if (Current->MarkedButton->highlighted && Current->MarkedButton->clicked)
	{
		Current->MarkedButton->UseFunction();
	}
	*/
}

void State_Menu::Render()
{
	//graphicEngine->CreateGraphicInstance(??, ??)
}