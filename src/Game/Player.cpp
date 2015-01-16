#include "Player.h"
#include "../Globals.h"
#include "../Graphics/GraphicEngine.h"
#include "../InputMap.h"


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

void Player::Update()
{
	if (key_arrows[UP])		y -= velocity;
	if (key_arrows[DOWN])	y += velocity;
	if (key_arrows[LEFT])	x -= velocity;
	if (key_arrows[RIGHT])	x += velocity;

}