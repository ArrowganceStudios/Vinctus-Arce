#include "../Globals.h"
#include "../InputMap.h"
#include "MenuActions.h"

void State_Menu::Init()
{	
	LoadResources();

	mainMenu = new Menu("Main Menu");
	characterSelectionMenu = new Menu("Character Selection");
	optionsMenu = new Menu("Options");
	pauseMenu = new Menu("Surrender?");
	waveMenu = new Menu("Next Wave");

	mainMenu->AddButton("Start Game", MenuActions::CharacterSelection);
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

	//characterSelectionMenu->AddClassIconBig("Warrior", MenuActions::WarriorClassSelected); //this will be derived from button probably
	//characterSelectionMenu->AddClassIconBig("Mage", MenuActions::MageClassSelected);
	//characterSelectionMenu->AddClassIconBig("Ranger", MenuActions::RangerClassSelected);
	characterSelectionMenu->AddButton("Begin", 570, 520, MenuActions::StartGame);
	characterSelectionMenu->AddButton("Back", 240, 520, MenuActions::Back);

	menuList = {mainMenu, characterSelectionMenu, optionsMenu, pauseMenu, waveMenu};
	SwitchToMenu("Main Menu");
}

void State_Menu::SwitchToMenu(string newMenu)
{
	if (CurrentMenu != nullptr)
	{
		CurrentMenu->Hide();
		for (auto button : CurrentMenu->buttons)
			button->Hide();
	}
	for(auto menuit : menuList)
	{
		if (menuit->menuTitle == newMenu)
		{
			CurrentMenu = menuit;
			CurrentMenu->Show();
			for (auto button : CurrentMenu->buttons)
				button->Show();
		}
	}

}

void State_Menu::Cleanup()
{
	for (auto button : characterSelectionMenu->buttons)
		delete button;
	while (!menuList.empty())
	{

		menuList.back()->Cleanup();
		menuList.clear();
	}
	menuList.shrink_to_fit();

	delete characterSelectionMenu;
	delete mainMenu;
	delete optionsMenu;
	delete pauseMenu;
	delete waveMenu;
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
	using ::ButtonState; //zis is kruszal!

	for (unsigned int i = 0; i < CurrentMenu->buttons.size(); i++)
	{
		if ((mouseX >= (CurrentMenu->buttons[i]->x - CurrentMenu->buttons[i]->width / 2)) &&
			(mouseX <= (CurrentMenu->buttons[i]->x + CurrentMenu->buttons[i]->width / 2)) &&
			(mouseY >= (CurrentMenu->buttons[i]->y - CurrentMenu->buttons[i]->height / 2)) &&
			(mouseY <= (CurrentMenu->buttons[i]->y + CurrentMenu->buttons[i]->height / 2)))
		{
			if (CurrentMenu->MarkedButton != CurrentMenu->buttons[i])
			{
				CurrentMenu->MarkedButton = CurrentMenu->buttons[i];
				CurrentMenu->buttons[i]->highlighted = true;
				graphicEngine->RequestUI_Element_Graphic(CurrentMenu->buttons[i], Hover);
			}
		}
		else
		{
			CurrentMenu->buttons[i]->highlighted = false;
			if (CurrentMenu->buttons[i]->clicked) CurrentMenu->buttons[i]->clicked = false;
			graphicEngine->RequestUI_Element_Graphic(CurrentMenu->buttons[i], Default);
		}
	}
	if (mouse[LMB] && CurrentMenu->MarkedButton != NULL && CurrentMenu->MarkedButton->highlighted)
	{

			CurrentMenu->MarkedButton->clicked = true;
			graphicEngine->RequestUI_Element_Graphic(CurrentMenu->MarkedButton, Clicked);
	}
	else if (!mouse[LMB] && CurrentMenu->MarkedButton != NULL && CurrentMenu->MarkedButton->clicked)
	{
		//cout << "Action!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		graphicEngine->RequestUI_Element_Graphic(CurrentMenu->MarkedButton, Default);
		CurrentMenu->MarkedButton->clicked = false;
		CurrentMenu->MarkedButton->UseFunction();
	}
	CurrentMenu->MarkedButton = NULL;
	/////////////////////////////////////////////////////////////////////
	/*if (CurrentMenu->MarkedButton != NULL)		// Small but fancy debug!
	{
		if (CurrentMenu->MarkedButton->clicked) cout << "Clicked!" << endl;
		else cout << "Highlighted!" << endl;
	}
	else cout << "---" << endl;*/
}

void State_Menu::LoadResources()
{
	//Graphics
	//menu
	ALLEGRO_BITMAP *menu = nullptr;
	menu = al_load_bitmap("assets/img/UI/Menu.jpg");

	std::vector<ALLEGRO_BITMAP *> menu_bitmap{ menu };

	graphicEngine->DefineUI_Element_Graphic("class Menu", menu_bitmap);

	//buttons
	ALLEGRO_BITMAP *default = nullptr;
	default = al_load_bitmap("assets/img/UI/button.png");
	ALLEGRO_BITMAP *hover = nullptr;
	hover = al_load_bitmap("assets/img/UI/button_highlighted.png");
	ALLEGRO_BITMAP *clicked = nullptr;
	clicked = al_load_bitmap("assets/img/UI/button_clicked.png");

	std::vector<ALLEGRO_BITMAP *> button_bitmaps{ default, hover, clicked };

	graphicEngine->DefineUI_Element_Graphic("class Button", button_bitmaps);

	//Sounds
}