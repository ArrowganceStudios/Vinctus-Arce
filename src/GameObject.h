#pragma once
#include <iostream>
#include <vector>
#include <allegro5\allegro.h>
#include "Sprite.h"

using namespace std;

class Sprite;

class GameObject
{
private:
	bool alive;

protected:
	float x;
	float y;

	vector<Sprite *> animations; // ??? <- I think that this should be just sent to Graphic Engine, and handled there.
public:
	GameObject();

	void Init(float x, float y);

	void virtual Update() {};
	void virtual Render() {}; // I doubt it's gonna be needed since we are having a GraphicEngine
	
	void DefineAnimation(int maxFrame, int curFrame, int frameCount, int frameDelay, int frameWidth, int framHeight,
		int animationColumns, ALLEGRO_BITMAP *image = NULL); //defining a sprite, and adding it to the vector of animations.

	float GetX() const { return x; }
	float GetY() const { return y; }

	bool IsAlive() const { return alive; }
	void SetAlive(bool alive) { GameObject::alive = alive; }
};