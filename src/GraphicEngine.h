#pragma once
#include <allegro5\allegro.h>
#include <vector>
#include "GameEngine.h"
#include "GameObject.h"
#include "Sprite.h"

class GameEngine;

class GraphicEngine
{
	int id;
	//class pointers
	std::vector <GameObject *> objectList; //list storing all rendered objects
	std::vector <Sprite *> sprites; // this needs to be sorted out diffrently, using 2d arrays
	//allegro variables
	//(tumbleweed)
public:
	GraphicEngine();

	void Init(){}; //??
	void Render(){};

	void CreateGraphicInstance(GameObject *object, int id);
	void DefineAnimation();
	void RequestAnimation();

	void Destroy(){};
};