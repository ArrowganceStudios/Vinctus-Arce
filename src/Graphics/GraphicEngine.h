#pragma once
#include <allegro5\allegro.h>
#include <vector>
#include "../GameEngine.h"
#include "../Game/GameObject.h"
#include "Sprite.h"
#include "UI/UI_element.h"

class GameEngine;

class GraphicEngine
{
	int id;
	//class pointers
	std::vector <UI_element *> UIelementList;
	std::vector <GameObject *> objectList; //list storing all rendered objects
	std::vector <Sprite *> sprites; // this needs to be sorted out diffrently, using 2d arrays
	//allegro variables
	//(smoke weed every day)
public:
	GraphicEngine();

	void Init(){}; //??
	void Render(){};

	void CreateGraphicInstance(GameObject *object,int id);
	void DefineUI_Element_Graphic(UI_element *element, std::vector<ALLEGRO_BITMAP *> bitmaps);
 	void CreateUI_Element_GraphicInstance(UI_element *element);
	void DefineAnimation(GameObject * gameObject, std::vector<Sprite *> animations);
	void RequestAnimation(GameObject *gameObject, int animationNumber);
	void RequestUI_Element_Graphic(UI_element *element, int graphicNumber);

	void Destroy(){};
};