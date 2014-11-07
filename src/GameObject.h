#pragma once
#include <iostream>

class GameObject
{
private:
	bool alive;

protected:
	float x;
	float y;

	//Sprite *sprite; // ???
public:
	GameObject();

	void Init(float x, float y);

	void virtual Update() {};
	void virtual Render() {};

	float GetX() const { return x; }
	float GetY() const { return y; }

	bool IsAlive() const { return alive; }
	void SetAlive(bool alive) { GameObject::alive = alive; }
};