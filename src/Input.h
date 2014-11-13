#pragma once
#include <allegro5/allegro.h>

class InputHandler
{
public:
	void Init();
	void Update(ALLEGRO_EVENT *event);
};