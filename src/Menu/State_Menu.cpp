//#include "State_Menu.h"
#include "../Globals.h"
//#include "../GameEngine.h"
//#include "../Graphics/GraphicEngine.h"
#include "../InputMap.h"
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


	menuList = {mainMenu, optionsMenu, pauseMenu, waveMenu};
	SwitchToMenu("Main Menu");
}

void State_Menu::SwitchToMenu(string newMenu)
{
	for(auto menuit : menuList)
	{
		if(menuit->menuTitle == newMenu)
			CurrentMenu = menuit;	//???
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
	for (int i = 0; i < CurrentMenu->buttons.size(); i++)
	{
		if ((mouseX >= (CurrentMenu->buttons[i]->x - CurrentMenu->buttons[i]->width / 2)) &&
			(mouseX <= (CurrentMenu->buttons[i]->x + CurrentMenu->buttons[i]->width / 2)) &&
			(mouseY >= (CurrentMenu->buttons[i]->y - CurrentMenu->buttons[i]->height / 2)) &&
			(mouseY <= (CurrentMenu->buttons[i]->y + CurrentMenu->buttons[i]->height / 2)))
		{
			CurrentMenu->buttons[i]->highlighted = true;
			if (CurrentMenu->MarkedButton == NULL) CurrentMenu->MarkedButton = CurrentMenu->buttons[i];
			break;
		}
		else
		{
			CurrentMenu->buttons[i]->highlighted = false;
			if (CurrentMenu->MarkedButton != NULL) CurrentMenu->MarkedButton = NULL;
			if (CurrentMenu->buttons[i]->clicked) CurrentMenu->buttons[i]->clicked = false;
		}
	}
	if (mouse[LMB])
	{
		if (CurrentMenu->MarkedButton != NULL && CurrentMenu->MarkedButton->highlighted) CurrentMenu->MarkedButton->clicked = true;
	}
	if (CurrentMenu->MarkedButton->highlighted && CurrentMenu->MarkedButton->clicked)
	{
		CurrentMenu->MarkedButton->UseFunction();
	}
}

void State_Menu::Render()
{
	//graphicEngine->CreateGraphicInstance(??, ??)
}