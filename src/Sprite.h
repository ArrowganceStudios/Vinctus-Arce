#pragma once
#include <allegro5\allegro.h>

class Sprite
{
	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int animationColumns;

	ALLEGRO_BITMAP *image;
public:
	Sprite(int maxFrame, int curFrame, int frameCount, int frameDelay, int frameWidth, int frameHeight, 
		   int animationColumns, ALLEGRO_BITMAP *image = NULL);
	~Sprite();

	int GetMaxFrame() const { return maxFrame; }
	int GetCurFrame() const { return curFrame; }
	int GetFrameCount() const { return frameCount; }
	int GetFrameDelay() const { return frameDelay; }
	int GetFrameWidth() const { return frameWidth; }
	int GetFrameHeight() const { return frameHeight; }
	int GetAnimationColumns () const { return animationColumns; }
};