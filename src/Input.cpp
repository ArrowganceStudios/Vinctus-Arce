#include "Input.h"
#include "InputMap.h"

bool key_arrows[4] = { false, false, false, false };
bool key_general[2] = { false, false };
bool mouse[2] = { false, false };
float mouseX = 0;
float mouseY = 0;


void InputHandler::Update(ALLEGRO_EVENT *event)
{
	if(event->type == ALLEGRO_EVENT_KEY_DOWN)
		switch(event->keyboard.keycode)
		{
			case ALLEGRO_KEY_UP:
              	 key_arrows[UP] = true;
				 break;
            case ALLEGRO_KEY_DOWN:
              	 key_arrows[DOWN] = true;
				 break;
            case ALLEGRO_KEY_LEFT: 
              	 key_arrows[LEFT] = true;
				 break;
            case ALLEGRO_KEY_RIGHT:
               	key_arrows[RIGHT] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				key_general[SPACE] = true;
				break;
            default:
            	break;
		}
	else if(event->type == ALLEGRO_EVENT_KEY_UP)
         switch(event->keyboard.keycode) 
		 {
            case ALLEGRO_KEY_UP:
               key_arrows[UP] = false;
			   break;
            case ALLEGRO_KEY_DOWN:
               key_arrows[DOWN] = false;
			   break;
            case ALLEGRO_KEY_LEFT: 
               key_arrows[LEFT] = false;
			   break;
            case ALLEGRO_KEY_RIGHT:
               key_arrows[RIGHT] = false;
			   break;
			case ALLEGRO_KEY_SPACE:
				key_general[SPACE] = false;
				break;
            default:
            	break;
         }
    if(event->type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		mouseX = event->mouse.x;
		mouseY = event->mouse.y;
	}
	if(event->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		if(event->mouse.button & 1)
			mouse[LMB] = true;
		if(event->mouse.button & 2)
			mouse[RMB] = true;
	}
	else if(event->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
	{
		if(event->mouse.button & 1)
			mouse[LMB] = false;
		if(event->mouse.button & 2)
			mouse[RMB] = false;
	}
}