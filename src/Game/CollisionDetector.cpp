#include "CollisionDetector.h"
#include "../Globals.h"
#include "allegro5\allegro_primitives.h"

using namespace std;

CollisionDetector::CollisionDetector() : display(false)
{
	//(..)
}

void CollisionDetector::CreateHitbox(GameObject *owner, int radius)
{
	Hitbox newHitbox(owner, radius);
	hitboxList.push_back(newHitbox);
}

void CollisionDetector::Update()
{
	if (hitboxList.size() > 2)
		for (unsigned int i = 0; i < hitboxList.size(); i++)
			for (unsigned int j = i + 1; j < hitboxList.size(); j++)
				if (hitboxList[i].CollidesWith(hitboxList[j]))
					cout << "Objects have collided" << endl; //temp
}

void CollisionDetector::RenderHitboxes()
{
	if (display)
		for (auto hitbox : hitboxList)
			al_draw_filled_circle(hitbox.GetDisplayedX(), hitbox.GetDisplayedY(), hitbox.GetRadius(), al_map_rgba_f(255, 0, 0, 0.2));
}

void CollisionDetector::EnableHitboxDisplay(bool display)
{
	CollisionDetector::display = display;
}

void CollisionDetector::Cleanup()
{
	hitboxList.clear();
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
	float dx = (GetX() + GetRadius()) - (otherHitbox.GetX() + otherHitbox.GetRadius());
	float dy = (GetY() + GetRadius()) - (otherHitbox.GetY() + otherHitbox.GetRadius());

	float distance = sqrt(dx * dx + dy * dy);
	
	if (distance < GetRadius() + otherHitbox.GetRadius())
		return true;
	else
		return false;
}

