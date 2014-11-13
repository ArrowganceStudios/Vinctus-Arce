#pragma once
#include <allegro5\allegro.h>
#include <vector>
#include "GameEngine.h"
#include "GameObject.h"
#include "Sprite.h"

class GameEngine;

class GraphicEngine
{
	//class pointers
	std::vector <GameObject *> objectList; //list storing all rendered objects
	std::vector <Sprite *> sprites; // this needs to be sorted out diffrently, using 2d arrays
	//allegro variables
	//(smoke weed every day)
public:
	GraphicEngine();

	void Init(){}; //??
	void Render(){};

	void CreateGraphicInstance(GameObject *object);
//	void CreateUI_Element_GraphicInstance(UI_element *element); <-- some problem
	void DefineAnimation(GameObject * gameObject, std::vector<Sprite *> animations);
	void RequestAnimation();

	void Destroy(){};
};