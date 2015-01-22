#pragma once
#include "Character.h"

class Player : public Character
{
public:

	Player();

	void Init(float x, float y, float velocity);

	int GetMeleeStrikeDamage();

	void GrantXP(int xp) { experience += xp; }
	int SetXP(int xp) { experience = xp; }
	int GetCurrentXP() const { return experience; }
	bool CanLevelUp() const { if (experience > maxExperience) { return true; } }

	void SetResourceLevelTo(int newResource) { resource = newResource; }
	void DecreaseResourceLevelBy(int amount) { resource -= amount; if (resource < 0) resource = 0; }
	void IncreaseResourceLevelBy(int amount) { resource += amount; if (resource > maxResourceLevel) resource = maxResourceLevel; }
	void SetMaxResourceLevelTo(int amount) { maxResourceLevel = amount; }
	int GetResourceAmount() const { return resource; }
	bool HasEnoughOfResource(int cost) const { if (cost < resource) return true; else return false; }

	virtual void Update();

private:

	//ClassType choosenClass;

	int maxExperience;
	int experience;
	int resource;
	int maxResourceLevel;
};