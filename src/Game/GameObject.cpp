#include "GameObject.h"
#include "../Globals.h"


GameObject::GameObject()
{
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

float GameObject::GetDisplayedX() const
{
	return (SCREEN_WIDTH / 2 - camera::Instance().GetCenterX() + GetX());
}

float GameObject::GetDisplayedY() const
{
	return (SCREEN_WIDTH / 2 - camera::Instance().GetCenterY() + GetY());
}
