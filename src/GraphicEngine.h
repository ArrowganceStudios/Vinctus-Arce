#pragma once
#include <allegro5\allegro.h>
#include <vector>
#include "GameEngine.h"

class GameEngine;

class GraphicEngine
{
	//consts
	const int FPS;
	const int WIDTH;
	const int HEIGHT;

	//class pointers
	//std::vector <GameObject *> objectList; //list storing all rendered objects

	//allegro variables
	ALLEGRO_DISPLAY *display; //I dunno whether this should be here or rather at GameEngine
public:
	GraphicEngine(float FPS, int w, int h);
	void Init(){}; //??
	void Render(){};
	void Destroy(){};
	void CreateGraphicInstance(/*some arguments to be put here in the future*/);
};