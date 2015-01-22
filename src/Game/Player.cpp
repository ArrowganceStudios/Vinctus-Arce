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
	SetName("Waclaw");
}

void Player::Init(float x, float y, float velocity) 
{
	Character::Init(x, y, velocity);

	graphicEngine::Instance().CreateAnimationInstance(this);
	gameEngine::Instance().GetCollisionDetector()->CreateHitbox(this, 25);
	
	Show();
}

int Player::GetMeleeStrikeDamage()
{
	return 5; //deals 5 dmg
}

void Player::Update()
{
	SetGlobalCooldown(GetGlobalCooldown() - 1);

	if (key_arrows[UP] || key_arrows[DOWN] || key_arrows[LEFT] || key_arrows[RIGHT]) PlayAnimation();
	else
	{
		StopAnimation();
		SetCurFrame(0);
	}

	if (key_arrows[UP])
	{
		graphicEngine::Instance().RequestAnimation(this, 0);
		y -= velocity;
	}
	if (key_arrows[DOWN])
	{
		graphicEngine::Instance().RequestAnimation(this, 1);
		y += velocity;
	}
	if (key_arrows[LEFT])
	{
		graphicEngine::Instance().RequestAnimation(this, 2);
		x -= velocity;
	}
	if (key_arrows[RIGHT])
	{
		graphicEngine::Instance().RequestAnimation(this, 3);
		x += velocity;
	}
	if (mouse[LMB] && !GetGlobalCooldown())
	{
		gameEngine::Instance().GetCollisionDetector()->CreateAttack(this, 10, 10, 10);
		SetGlobalCooldown(15);
	}
}