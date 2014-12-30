#include "../Globals.h"
#include "../InputMap.h"
#include "MenuActions.h"
#include "MenuButton.h"
#include "ClassSelectionIcon.h"

void State_Menu::Init()
{	
	LoadResources();

	isCleanedUp = false;

	mainMenu = new Menu("Main Menu");
	characterSelectionMenu = new Menu("Character Selection");
	optionsMenu = new Menu("Options");
	resolutionMenu = new Menu("Resolution Settings");
	creditsMenu = new Menu("Credits");
	pauseMenu = new Menu("Surrender?");
	waveMenu = new Menu("Wave Menu");

	mainMenu->AddButton("Start Game", MenuActions::CharacterSelection);
	mainMenu->AddButton("Options", MenuActions::Options);
	mainMenu->AddButton("Credits", MenuActions::Credits);
	mainMenu->AddButton("Exit", MenuActions::Exit);

	optionsMenu->AddButton("Resolution", MenuActions::Resolution);
	optionsMenu->AddButton("Sound", MenuActions::Sound);
	optionsMenu->AddButton("Back", MenuActions::Back);
	
	creditsMenu->AddImage(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 530, 190, 0);
	creditsMenu->AddButton("Back", SCREEN_WIDTH / 2, SCREEN_HEIGHT - 100, MenuActions::Back);

	pauseMenu->AddButton("Yesh", MenuActions::Yesh);
	pauseMenu->AddButton("Nah", MenuActions::Nah);

	waveMenu->AddButton("Continue", MenuActions::Continue);
	waveMenu->AddButton("Surrender", MenuActions::Surrender);

	characterSelectionMenu->AddClassIconBig(ClassIconGraphic::WarriorClicked, nullptr);
	characterSelectionMenu->AddClassIconBig(ClassIconGraphic::Disabled, nullptr);
	characterSelectionMenu->AddClassIconBig(ClassIconGraphic::Disabled, nullptr);
	characterSelectionMenu->AddButton("Begin", 570, 520, MenuActions::StartGame);
	characterSelectionMenu->AddButton("Back", 240, 520, MenuActions::Back);

	resolutionMenu->AddImage(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SliderDimension::sliderBarWidth, SliderDimension::sliderBarHeight, 1);
	resolutionMenu->AddImage(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SliderDimension::sliderWidth, SliderDimension::sliderHeight, 2);
	resolutionMenu->AddButton("Back", SCREEN_WIDTH / 2, SCREEN_HEIGHT - 100, MenuActions::Options);

	menuList = { mainMenu, characterSelectionMenu, optionsMenu, resolutionMenu, creditsMenu, waveMenu, pauseMenu };
	SwitchToMenu("Main Menu");
}

void State_Menu::SwitchToMenu(string newMenu)
{
	if (CurrentMenu != nullptr)
	{
		CurrentMenu->Hide();
	}

	for(auto menuit : menuList)
	{
		if (menuit->menuTitle == newMenu)
		{
			CurrentMenu = menuit;
			CurrentMenu->Show();
		}
	}

}

void State_Menu::Cleanup()
{
	for (auto &menu : menuList)
		menu->Cleanup();

	CurrentMenu = nullptr;

	for (auto menu : menuList)
		if (menu != nullptr) delete menu;

		menuList.clear();
		menuList.shrink_to_fit();

	vector <string> UIGraphicsToBeDeleted = { "class ClassSelectionIcon", "class MenuButton", "class Image",
		"class Menu", "class Text" };

	for (auto &graphic : UIGraphicsToBeDeleted)
		graphicEngine::Instance().DestroyGraphic(graphic);

	graphicEngine::Instance().CleanUpUIMaps();

	Text::textID = 0;

	cout << "cleanup has ben called" << endl;
	isCleanedUp = true;
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

void State_Menu::Update()
{
	if (CurrentMenu)
	{
		MenuButton *clickedButton = nullptr;
		for (auto &button : CurrentMenu->buttons)
		{
			button->Update();
			if (button->WasClicked()) clickedButton = button;
		}

		if (clickedButton)
		{
			clickedButton->SetWasClickedToFalse();
			clickedButton->UseFunction();
		}
	}
}

void State_Menu::LoadResources()
{
	//Graphics
	//menu
	graphicEngine::Instance().DefineGraphic("class Menu", "assets/img/UI/Menu.jpg");

	//buttons
	graphicEngine::Instance().DefineGraphic("class MenuButton", "assets/img/UI/button.png");
	graphicEngine::Instance().DefineGraphic("class MenuButton", "assets/img/UI/button_highlighted.png");
	graphicEngine::Instance().DefineGraphic("class MenuButton", "assets/img/UI/button_clicked.png");

	//class icons
	graphicEngine::Instance().DefineGraphic("class ClassSelectionIcon", "assets/img/UI/LockedCrest.png");
	graphicEngine::Instance().DefineGraphic("class ClassSelectionIcon", "assets/img/UI/WarriorCrestNormal.png");
	graphicEngine::Instance().DefineGraphic("class ClassSelectionIcon", "assets/img/UI/WarriorCrestHovered.png");
	graphicEngine::Instance().DefineGraphic("class ClassSelectionIcon", "assets/img/UI/WarriorCrestClicked.png");

	//credits graphic
	graphicEngine::Instance().DefineGraphic("class Image", "assets/img/media/arrowgance.jpg");

	//slider
	graphicEngine::Instance().DefineGraphic("class Image", "assets/img/UI/SliderBar.png");
	graphicEngine::Instance().DefineGraphic("class Image", "assets/img/UI/Slider.png");

	//fonts
	graphicEngine::Instance().textManager->DefineFont("Morpheius", "assets/img/UI/Morpheius_vDark.png", 7, 72, 108, -30);

	//Sounds
}