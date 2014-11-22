#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <vector>
#include "../GameEngine.h"
#include "../Game/GameObject.h"
//#include "Sprite.h"
#include "UI/UI_element.h"
#include "UI/TextManager.h"
#include <map>

class GameEngine;
class TextManager;

class GraphicEngine
{
	//maps storing animations/graphics for each type of class
	std::map <std::string, std::vector<Sprite *>> GameObjectsAnimationsMap;
	std::map <std::string, std::vector<ALLEGRO_BITMAP *>> UI_elementsGraphicsMap;

	//maps storing an actual list of UI and Game objects and text instances
	std::vector <std::pair<GameObject *, Sprite *>> GameObjectsMap;
	std::vector <std::pair<UI_element *, ALLEGRO_BITMAP *>> UI_elementsMap;

public:
	GraphicEngine();
	~GraphicEngine() { delete textManager; };

	TextManager *textManager;

	void Init(){}; //??
	void Render();

	void DefineAnimation(string objectsClassName, std::vector<Sprite *> animations);
	void CreateGraphicInstance(GameObject *object);
	void RequestAnimation(GameObject *gameObject, int animationNumber);

	void DefineUI_Element_Graphic(string elementsClassName, string pathName);
	void DefineUI_Element_Graphic(string elementsClassName, ALLEGRO_BITMAP *bitmap);
	void DestroyUI_ElementGraphic(string className);

	void CreateUI_Element_GraphicInstance(UI_element *element);
	void DestroyUI_ElementGraphicInstance(UI_element *element);
	void RequestUI_Element_Graphic(UI_element *element, int graphicNumber);

	void CleanUpUIMaps();
	void Destroy();
};