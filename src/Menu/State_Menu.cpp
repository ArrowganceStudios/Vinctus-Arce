//#include "State_Menu.h"
#include "../Globals.h"
//#include "../GameEngine.h"
//#include "../Graphics/GraphicEngine.h"
#include "../InputMap.h"
#include "MenuActions.h"

void State_Menu::Init()
{	
	//just a test
	ALLEGRO_BITMAP *menu = nullptr;
	menu = al_load_bitmap("assets/img/UI/Menu.jpg");
	
	std::vector<ALLEGRO_BITMAP *> menu_bitmap { menu };

	graphicEngine->DefineUI_Element_Graphic("class Menu", menu_bitmap);

	//we need to fix this class UI_element * to use it for more than 1 object tho :D

	ALLEGRO_BITMAP *default = nullptr;
	default = al_load_bitmap("assets/img/UI/button.png");
	ALLEGRO_BITMAP *hover = nullptr;
	hover = al_load_bitmap("assets/img/UI/button_highlighted.png");
	ALLEGRO_BITMAP *clicked = nullptr;
	clicked = al_load_bitmap("assets/img/UI/button_clicked.png");

	std::vector<ALLEGRO_BITMAP *> button_bitmaps{ default, hover, clicked };

	graphicEngine->DefineUI_Element_Graphic("class Button", button_bitmaps); //temporary solution

	//end of the test

	mainMenu = new Menu("Main Menu");
	optionsMenu = new Menu("Options");
	pauseMenu = new Menu("Surrender?");
	waveMenu = new Menu("Next Wave");

	mainMenu->AddButton("Start Game", MenuActions::StartGame);
	mainMenu->AddButton("Options", MenuActions::Options);
	mainMenu->AddButton("Credits", MenuActions::Credits);
	mainMenu->AddButton("Exit", MenuActions::Exit);

	//optionsMenu->AddButton("Resolution", MenuActions::Resolution);
	//optionsMenu->AddButton("Sound", MenuActions::Sound);
	//optionsMenu->AddButton("Back", MenuActions::Back);
	
	//pauseMenu->AddButton("Yesh", MenuActions::Yesh);
	//pauseMenu->AddButton("Nah", MenuActions::Nah);

	//waveMenu->AddButton("Continue", MenuActions::Continue);
	//waveMenu->AddButton("Surrender", MenuActions::Surrender);


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
			graphicEngine->RequestUI_Element_Graphic(CurrentMenu->buttons[i], 2);
			if (CurrentMenu->MarkedButton == NULL) CurrentMenu->MarkedButton = CurrentMenu->buttons[i];
			break;
		}
		else
		{
			CurrentMenu->buttons[i]->highlighted = false;
			graphicEngine->RequestUI_Element_Graphic(CurrentMenu->buttons[i], 0);
			if (CurrentMenu->MarkedButton != NULL) CurrentMenu->MarkedButton = NULL;
			if (CurrentMenu->buttons[i]->clicked) CurrentMenu->buttons[i]->clicked = false;
		}
	}
	if (mouse[LMB])
	{
		if (CurrentMenu->MarkedButton != NULL && CurrentMenu->MarkedButton->highlighted) CurrentMenu->MarkedButton->clicked = true;
	}
	if (!mouse[LMB] && CurrentMenu->MarkedButton != NULL && CurrentMenu->MarkedButton->clicked)
	{
		cout << "Action!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		CurrentMenu->MarkedButton->UseFunction();
		CurrentMenu->MarkedButton->clicked = false;
	}/*
	if (CurrentMenu->MarkedButton != NULL)		// Small but fancy debug!
	{
		if (CurrentMenu->MarkedButton->clicked) cout << "Clicked!" << endl;
		else cout << "Highlighted!" << endl;
	}
	else cout << "---" << endl;*/
}

void State_Menu::Render()
{
	//graphicEngine->CreateGraphicInstance(??, ??)
}