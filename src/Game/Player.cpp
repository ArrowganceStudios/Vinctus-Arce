#include "Player.h"
#include "../Globals.h"
#include "../Graphics/GraphicEngine.h"
#include "../InputMap.h"
#include "../Menu/MenuActions.h"

Player::Player()
{
	maxExperience = 0;
	experience = 0;
	resource = 0;
	maxResourceLevel = 0;
	SetName("Waclaw");
}

Player::~Player()
{
	graphicEngine::Instance().DestroyAnimationInstance(this);
	gameEngine::Instance().GetCollisionDetector()->DestroyHitbox(this);
	gameEngine::Instance().GetCollisionDetector()->DestroyAttack(this);
#ifdef _DEBUG
	cout << "Player got destroyed" << endl;
#endif

	objectHandler::Instance().ClearTargets();
	camera::Instance().Init(nullptr);

	//MenuActions::Yesh();
}

void Player::Init(float x, float y, float velocity) 
{
	Character::Init(x, y, velocity);

	graphicEngine::Instance().CreateAnimationInstance(this);
	gameEngine::Instance().GetCollisionDetector()->CreateHitbox(this, 25);
	
	Show();
	SetMaxHealth(200);
	SetHealth(200);
}

int Player::GetMeleeStrikeDamage()
{
	return 25; //deals 5 dmg
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
		MoveUp();
	}
	if (key_arrows[DOWN])
	{
		MoveDown();
	}
	if (key_arrows[LEFT])
	{
		MoveLeft();
	}
	if (key_arrows[RIGHT])
	{
		MoveRight();
	}
	/*if (!(key_arrows[UP] || key_arrows[DOWN]))
	{
		directionY = 0;
	}
	else if (!(key_arrows[LEFT] || key_arrows[RIGHT]))
	{
		directionX = 0;
	}*/
	if (key_general[SPACE] && !GetGlobalCooldown())
	{
		MeleeAttack();
	}

	Character::Update();

	if (!IsAlive())

		Player::~Player();
}

void Player::MoveUp()
{
	directionY = -1;
	directionX = 0;
	graphicEngine::Instance().RequestAnimation(this, 0);
	y -= velocity;
}
void Player::MoveDown()
{
	directionY = 1;
	directionX = 0;
	graphicEngine::Instance().RequestAnimation(this, 1);
	y += velocity;
}
void Player::MoveLeft()
{
	directionX = -1;
	directionY = 0;
	graphicEngine::Instance().RequestAnimation(this, 2);
	x -= velocity;
}
void Player::MoveRight()
{
	directionX = 1;
	directionY = 0;
	graphicEngine::Instance().RequestAnimation(this, 3);
	x += velocity;
}

void Player::MeleeAttack()
{
	gameEngine::Instance().GetCollisionDetector()->CreateAttack(this, 20, directionX * 30, directionY * 30);
	SetGlobalCooldown(15);
}