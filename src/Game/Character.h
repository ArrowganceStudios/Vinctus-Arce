#pragma once
#include <string>
#include "MobileObject.h"

class Character : public MobileObject
{
public:
	Character() : name("unnamed"), health(0), maxHealth(0), armor(0), level(0), maxLevel(0) {};
	~Character() { };

	void Init(float x, float y, float velocity) { MobileObject::Init(x, y, velocity); }

	void SetName(std::string newName) { name = newName; }
	std::string GetName() const { return name; }

	void HealFor(int healthAdded) { health += healthAdded; if (health > maxHealth) health = maxHealth; }
	void DamageFor(int healthToLose) { health -= healthToLose; if (health < 0) health = 0; }
	void SetHealth(int health) { Character::health = health; }
	int GetHealth() const { return health; }

	void IncreaseMaxHealth(int healthAdded) { maxHealth += healthAdded; }
	void SetMaxHealth(int mHealth) { maxHealth = mHealth; }
	int GetMaxHealth() const { return maxHealth; }

	void SetArmorValue(int newArmor) { armor = newArmor; }
	int GetArmorValue() const { return armor; }

	void LevelUp() { if(level < maxLevel) level++; }
	void SetLevel(int newLevel) { level = newLevel; }
	void SetMaxLevel(int maxLev) { maxLevel = maxLev; }
	int GetLevel() const { return level; }

private:
	std::string name;

	int health;
	int maxHealth;

	int armor;

	int level;
	int maxLevel;
};
