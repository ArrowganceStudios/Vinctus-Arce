#include "GameObject.h"


GameObject::GameObject()
{
	SetAlive(true);
	x = 0;
	y = 0;
}

void GameObject::Init(float x, float y)
{
	GameObject::x = x;
	GameObject::y = y;
}

void GameObject::DefineAnimation(int maxFrame, int curFrame, int frameCount, int frameDelay, int frameWidth, int frameHeight,
	int animationColumns, ALLEGRO_BITMAP *image)
{
	Sprite *newAnimation = new Sprite(maxFrame, curFrame, frameCount, frameDelay, frameWidth, frameHeight, animationColumns, image);
	animations.push_back(newAnimation);
}