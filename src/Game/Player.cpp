#include "Player.h"
#include "../Globals.h"
#include "../Graphics/GraphicEngine.h"


Player::Player()
{
	maxExperience = 0;
	experience = 0;
	resource = 0;
	maxResourceLevel = 0;

}

void Player::Init(float x, float y, float velocity) 
{
	Character::Init(x, y, velocity);

	graphicEngine::Instance().CreateAnimationInstance(this);
	graphicEngine::Instance().RequestAnimation(this, 0);
	Show();
}