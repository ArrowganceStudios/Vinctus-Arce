#include "CollisionDetector.h"
#include "../Globals.h"
#include "../Common.h"
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
			//break; //commented since if we happen to have AoE spells which will persist on the ground they need to be removed as well
		}
	}
}

void CollisionDetector::Update()
{
	/*if (hitboxes.size() > 2)
		for (unsigned int i = 0; i < hitboxes.size(); i++)
			for (unsigned int j = i + 1; j < hitboxes.size(); j++)
				if (hitboxes[i].CollidesWith(hitboxes[j]))
					cout << hitboxes[i].GetOwner()->GetName() << " has collided with " << hitboxes[j].GetOwner()->GetName() << endl; //temp
*/
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
	attacks.clear();
}


float CollisionDetector::Hitbox::GetDisplayedX() const
{ 
	return owner->GetDisplayedX(); 
}

float CollisionDetector::Hitbox::GetDisplayedY() const
{
	return owner->GetDisplayedY();
}

bool CollisionDetector::CanStepOnto(CircleType object, int direction)
{
	int dx = 0;
	int dy = 0;

	switch (direction)
	{
	case Up:
		dy -= object.radius;
		break;
	case Down:
		dy += object.radius;
		break;
	case Left:
		dx -= object.radius;
		break;
	case Right:
		dx += object.radius;
		break;
	default:
		break;
	}

	char tileType = gameEngine::Instance().Instance().GetGameState()->GetMapLayer()->GetTileTypeAtCoords(object.center.x + dx, object.center.y + dy);
	RectangleType tile = gameEngine::Instance().Instance().GetGameState()->GetMapLayer()->GetTileMeshAt(object.center.x, object.center.y);

	if (!(tileType && CollisionBetween(object, tile)))
		return true;
	else
		return false;
}

bool CollisionDetector::CollisionBetween(CircleType circle, RectangleType rect)
{
	Point circleDistance;
	circleDistance.x = abs(circle.center.x - rect.center.x);
	circleDistance.y = abs(circle.center.y - rect.center.y);

	if (circleDistance.x > (rect.width / 2 + circle.radius)) { return false; }
	if (circleDistance.y > (rect.height / 2 + circle.radius)) { return false; }

	if (circleDistance.x <= (rect.width / 2)) { return true; }
	if (circleDistance.y <= (rect.height / 2)) { return true; }

	float cornerDistance_sq = (circleDistance.x - rect.width / 2) * (circleDistance.x - rect.width / 2) +
		(circleDistance.y - rect.height / 2) * (circleDistance.y - rect.height / 2);

	return (cornerDistance_sq <= (circle.radius * circle.radius));
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
	//if the classes are same, don't deal dmg
	if (typeid(*(hitbox.GetOwner())) == typeid(*attacker))
		return;
	
	float damage = attacker->GetMeleeStrikeDamage();
	
	hitbox.TakeDamage(damage);
}

