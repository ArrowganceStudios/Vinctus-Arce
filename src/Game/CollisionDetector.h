#pragma once
#include "GameObject.h"
#include "Character.h"
#include <vector>

class CollisionDetector
{
public:
	CollisionDetector();

	void CreateHitbox(Character *owner, int radius);
	void CreateAttack(Character *owner, int radius, float xOffset, float yOffset);

	void Update();
	void RenderHitboxes();
	void EnableHitboxDisplay(bool display);
	void Cleanup();

	void AttacksCleanup();
	void SetAttacksToInactive() { for (auto& attack : attacks) attack.SetToInactive(); }

	bool IsHitboxDisplayEnabled() const { return display; }
private:

	class Hitbox
	{
	public:
		Hitbox(Character* owner, int radius) :owner(owner), radius(radius) {};


		virtual float GetDisplayedX() const;
		virtual float GetDisplayedY() const;
		virtual float GetX() const { return owner->GetX(); }
		virtual float GetY() const { return owner->GetY(); }
		float GetRadius() const { return static_cast<float>(radius); }
		
		virtual bool CollidesWith(const Hitbox& otherHitbox);
		void TakeDamage(float damage);

		const Character* GetOwner() const { return owner; }

	private:
		Character *owner;
		int radius; //could be as well made as pointer to save memory but cba

	};

	class Attack : public Hitbox
	{
	public:
		Attack(Character* attacker, int radius, float xOffset, float yOffset)
			:Hitbox(nullptr, radius), attacker(attacker), xOffset(xOffset), yOffset(yOffset), active(true), fade(5) {}
		void DealDamageTo(Hitbox& hitbox);

		virtual float GetX() const { return attacker->GetX() + xOffset; }
		virtual float GetY() const { return attacker->GetY() + yOffset; }

		virtual float GetDisplayedX() const { return attacker->GetDisplayedX() + xOffset; } 
		virtual float GetDisplayedY() const { return attacker->GetDisplayedY() + yOffset; } 

		void SetToInactive() { active = false; }
		bool IsActive() const { return active; }

		int GetFade() const { return fade; }
		void DecreaseFade() { if(fade > 0) fade--; }

	private:
		Character *attacker;
		float xOffset;
		float yOffset;
		bool active;
		int fade;
	};

	std::vector <Hitbox> hitboxes;
	std::vector <Attack> attacks;
	bool display;
	public: void DestroyHitbox(Character *owner);

};

