#include "Yeti.h"
#include "../Globals.h"
#include "../Graphics/GraphicEngine.h"

int Yeti::counter = 0;

Yeti::Yeti()
{
	SetName("Yeti");
	SetMaxHealth(NPCSheet::Yeti::MaxHealth);
	SetHealth(NPCSheet::Yeti::MaxHealth);
	SetArmorValue(NPCSheet::Yeti::Armor);
	SetPower(NPCSheet::Yeti::Power);

	z = 2;

	Show();

	if (!counter)
	{
		Sprite *newSprite = new Sprite(1, 0, 1, 1, 64, 64, 1, al_load_bitmap("assets/img/npcs/yeti.png"));
		graphicEngine::Instance().DefineAnimation("class Yeti", newSprite);
	}

	graphicEngine::Instance().CreateAnimationInstance(this);
	gameEngine::Instance().GetCollisionDetector()->CreateHitbox(this, 25);

	counter++;

#ifdef _DEBUG
	cout << "Yeti got created" << endl;
#endif
}

Yeti::~Yeti()
{
	counter--;
	if (!counter)
		graphicEngine::Instance().DestroyAnimation("class Yeti");
	graphicEngine::Instance().DestroyAnimationInstance(this);
#ifdef _DEBUG
	cout << "Yeti got destroyed" << endl;
#endif
}

void Yeti::MeleeAttack()
{
	gameEngine::Instance().GetCollisionDetector()->CreateAttack(this, 10, 0, 0);
	SetGlobalCooldown(15);
}

int Yeti::GetMeleeStrikeDamage()
{
	return 5;
}

void Yeti::Update()
{
	Character::Update();

	if (!IsAlive())
		Yeti::~Yeti();
	else
		AI();
}

void Yeti::AI()
{
	SetGlobalCooldown(GetGlobalCooldown() - 1);

	if (GetTarget() == nullptr) return;

	if (GetTarget()->GetX() > x)
		MoveRight();
	else if (GetTarget()->GetX() < x)
		MoveLeft();

	if (GetTarget()->GetY() > y)
		MoveDown();
	else if (GetTarget()->GetY() < y)
		MoveUp();

	if (!GetGlobalCooldown())
		MeleeAttack();
}

void Yeti::MoveUp()
{
	y -= velocity;
}

void Yeti::MoveDown()
{
	y += velocity;
}

void Yeti::MoveLeft()
{
	x -= velocity;
}

void Yeti::MoveRight()
{
	x += velocity;
}