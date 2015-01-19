#pragma once
#include "GameObject.h"
#include <vector>

class CollisionDetector
{
public:
	CollisionDetector();

	void CreateHitbox(GameObject *owner, int radius);

	void Update();
	void RenderHitboxes();
	void EnableHitboxDisplay(bool display);
	void Cleanup();

	bool IsHitboxDisplayEnabled() const { return display; }
private:

	class Hitbox
	{
	public:
		Hitbox(GameObject* owner, int radius) :owner(owner), radius(radius) {};

		float GetDisplayedX() const;
		float GetDisplayedY() const;
		float GetX() const { return owner->GetX(); }
		float GetY() const { return owner->GetY(); }
		float GetRadius() const { return static_cast<float>(radius); }
		
		bool CollidesWith(const Hitbox& otherHitbox);
	private:
		GameObject *owner;
		int radius; //could be as well made as pointer to save memory but cba

	};

	std::vector <Hitbox> hitboxList;
	bool display;
};

