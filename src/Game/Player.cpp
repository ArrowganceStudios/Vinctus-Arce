#include "Player.h"
#include "../Globals.h"
#include "../Graphics/GraphicEngine.h"


Player::Player()
{
	maxExperience = 0;
	experience = 0;
	resource = 0;
	maxResourceLevel = 0;

	heroSprite = new Sprite(16, 0, 0, 5, 64, 64,
		4, al_load_bitmap("assets/custom_hero.png"));
}


Player::~Player()
{
	delete heroSprite;
}

void Player::Init(float x, float y, float velocity) 
{
	Character::Init(x, y, velocity);
	graphicEngine::Instance().CreateAnimationInstance(this);
	
}