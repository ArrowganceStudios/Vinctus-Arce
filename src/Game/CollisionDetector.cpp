#include "CollisionDetector.h"
#include "../Globals.h"
#include "allegro5\allegro_primitives.h"

using namespace std;

CollisionDetector::CollisionDetector() : display(false)
{
	//(..)
}

void CollisionDetector::CreateHitbox(Character *owner, int radius)
{
	Hitbox newHitbox(owner, radius);
	hitboxes.push_back(newHitbox);
#ifdef _DEBUG
	cout << "Hitbox got created" << endl;
#endif
}

void CollisionDetector::CreateAttack(Character *owner, int radius, float xOffset, float yOffset)
{
	Attack attack(owner, radius, xOffset, yOffset);
	attacks.push_back(attack);
#ifdef _DEBUG
	cout << "Attack got created" << endl;
#endif
}

void CollisionDetector::DestroyHitbox(Character *owner)
{
	for (unsigned int i = 0; i < hitboxes.size(); i++)
	{
		if (hitboxes[i].GetOwner() == owner)
		{
			hitboxes.erase(hitboxes.begin() + i);
#ifdef _DEBUG
			cout << "Hitbox got destroyed" << endl;
#endif
			break;
		}
	}
}

void CollisionDetector::DestroyAttack(Character *owner)
{
	for (unsigned int i = 0; i < attacks.size(); i++)
	{
		if (attacks[i].GetAttacker() == owner)
		{
			attacks[i].SetToInactive();
			attacks.erase(attacks.begin() + i);
#ifdef _DEBUG
			cout << "Attack got destroyed" << endl;
#endif
			break;
		}
	}
}

void CollisionDetector::Update()
{
	/*if (hitboxes.size() > 2)
		for (unsigned int i = 0; i < hitboxes.size(); i++)
			for (unsigned int j = i + 1; j < hitboxes.size(); j++)
				if (hitboxes[i].CollidesWith(hitboxes[j]));*/
				//	cout << hitboxes[i].GetOwner()->GetName() << " has collided with " << hitboxes[j].GetOwner()->GetName() << endl; //temp

	if (!attacks.empty())
		for (unsigned int i = 0; i < hitboxes.size(); i++)
			for (unsigned int j = 0; j < attacks.size(); j++)
				if (hitboxes[i].CollidesWith(attacks[j]) && attacks[j].IsActive())
					attacks[j].DealDamageTo(hitboxes[i]);

	SetAttacksToInactive();
}

void CollisionDetector::RenderHitboxes()
{
	if (display)
	{
		for (auto hitbox : hitboxes)
			al_draw_filled_circle(hitbox.GetDisplayedX(), hitbox.GetDisplayedY(), hitbox.GetRadius(), al_map_rgba_f(0, 255, 0, 0.2));

		for (auto attack : attacks)
			al_draw_filled_circle(attack.GetDisplayedX(), attack.GetDisplayedY(), attack.GetRadius(), al_map_rgba_f(255, 0, 0, 0.2));
	}

	AttacksCleanup();
}

void CollisionDetector::EnableHitboxDisplay(bool display)
{
	CollisionDetector::display = display;
}

void CollisionDetector::AttacksCleanup()
{
	for (unsigned int i = 0; i < attacks.size(); i++)
	{
		attacks[i].DecreaseFade();
		if (!attacks[i].GetFade()) //if fade = 0
			attacks.erase(attacks.begin() + i);
	}
	attacks.shrink_to_fit();
}

void CollisionDetector::Cleanup()
{
	hitboxes.clear();
}


float CollisionDetector::Hitbox::GetDisplayedX() const
{ 
	return owner->GetDisplayedX(); 
}

float CollisionDetector::Hitbox::GetDisplayedY() const
{
	return owner->GetDisplayedY();
}

bool CollisionDetector::Hitbox::CollidesWith(const Hitbox& otherHitbox)
{
	float dx = (GetX()) - (otherHitbox.GetX());
	float dy = (GetY()) - (otherHitbox.GetY());

	float distance = sqrt(dx * dx + dy * dy);
	
	if (distance < GetRadius() + otherHitbox.GetRadius())
		return true;
	else
		return false;
}

void CollisionDetector::Hitbox::TakeDamage(float damage)
{
	cout << "Health drops from " << owner->GetHealth() << "HP to ";
	owner->DamageFor(damage);
	cout << owner->GetHealth() << "HP. "<< endl;
}

void CollisionDetector::Attack::DealDamageTo(Hitbox& hitbox)
{
	float damage = attacker->GetMeleeStrikeDamage();
	
	if (attacker == hitbox.GetOwner())
		return;

	const std::type_info& info = typeid(*(hitbox.GetOwner()));
	string className = static_cast<string>(info.name());

	const std::type_info& info2 = typeid(*attacker);
	string className2 = static_cast<string>(info2.name());
	
	if (className == className2) return;

	hitbox.TakeDamage(damage);
}

