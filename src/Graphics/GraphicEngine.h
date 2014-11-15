#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <vector>
#include "../GameEngine.h"
#include "../Game/GameObject.h"
//#include "Sprite.h"
#include "UI/UI_element.h"
#include <map>

class GameEngine;

class GraphicEngine
{
	//maps storing animations/graphics for each type of class
	std::map <std::string, std::vector<Sprite *>> GameObjectsAnimationsMap;
	std::map <std::string, std::vector<ALLEGRO_BITMAP *>> UI_elementsGraphicsMap;

	//maps storing an actual list of UI and Game objects
	std::map <GameObject *, Sprite *> GameObjectsMap; //should be multimaps actually
	std::map <UI_element *, ALLEGRO_BITMAP *> UI_elementsMap; 

	//allegro variables
	//(smoke weed every day)
public:
	GraphicEngine();

	void Init(){}; //??
	void Render();

	void DefineAnimation(string objectsClassName, std::vector<Sprite *> animations);
	void CreateGraphicInstance(GameObject *object);
	void RequestAnimation(GameObject *gameObject, int animationNumber);

	void DefineUI_Element_Graphic(string elementsClassName, std::vector<ALLEGRO_BITMAP *> bitmaps);
	void CreateUI_Element_GraphicInstance(UI_element *element);
	void RequestUI_Element_Graphic(UI_element *element, int graphicNumber);

	void Destroy(){};
};