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
	Character::~Character();
}