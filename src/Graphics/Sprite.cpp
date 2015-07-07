#include "Sprite.h"
#include <allegro5/allegro.h>

Sprite::Sprite(int maxFrame, int curFrame, int frameCount, int frameDelay, int frameWidth, int frameHeight, 
		   int animationColumns, ALLEGRO_BITMAP *image) 
		   : maxFrame(maxFrame), curFrame(curFrame), frameCount(frameCount), frameDelay(frameDelay), 
		     frameWidth(frameWidth), frameHeight(frameHeight), animationColumns(animationColumns)
{
	if(image != NULL) Sprite::image = image;
}

Sprite::~Sprite()
{
	al_destroy_bitmap(image);
}
