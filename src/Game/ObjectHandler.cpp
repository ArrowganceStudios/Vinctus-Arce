#include "ObjectHandler.h"
#include "MobileObject.h"
#include "Yeti.h"
#include "StaticObject.h"
#include "../Globals.h"
#include "allegro5/allegro.h"
#include <iostream>


//ObjectHandler* ObjectHandler::instance = nullptr; //this definition is needed, without it we get unrsolved link external 2001

ObjectHandler::ObjectHandler()
{

}

template<class Type> void ObjectHandler::CreateObject(float x, float y)	
{
	/*if (!(std::is_base_of(GameObject, Type)))
	{
		cerr << "Provided type isn't a game object" << endl;
		return;
	}*/

	float width = al_get_bitmap_width(graphicEngine::Instance().GetMapBitmap());
	float height = al_get_bitmap_height(graphicEngine::Instance().GetMapBitmap());

	if (std::is_same<Type, Player>::value)
	{
		Player *object = new Player();
		object->Init(x, y, 3);
		objects.push_back(object);
		mobiles.push_back(object);
		player = object;

		camera::Instance().Init(object);
	}
	else if (std::is_same<Type, Yeti>::value)
	{
		Yeti *object = new Yeti();
		object->Init(x, y, 1);
		objects.push_back(object);
		mobiles.push_back(object);
		NPCs.push_back(object);

		object->SetTarget(player);
	}
	else if (std::is_same<Type, StaticObject>::value)
	{
		StaticObject *object = new StaticObject();
		//object->Init(2, 2); 
		objects.push_back(object);
	}
}

template<class Type> void ObjectHandler::DestroyObject(Type *objectToDestroy)
{
	auto it = GetIterator(objectToDestroy);

	objects.erase(it);
	objects.shrink_to_fit();
	
	if (GetNPCIterator(objectToDestroy) != NPCs.end()) //if object to destroy is an actual NPC
	{
		NPCs.erase(GetNPCIterator(objectToDestroy));
		NPCs.shrink_to_fit();
#ifdef _DEBUG
		cout << "NPC got deleted" << endl;
#endif
	}

	if (GetMobileObjectIterator(objectToDestroy) != mobiles.end()) //if object to destroy is an actual NPC
	{
		mobiles.erase(GetMobileObjectIterator(objectToDestroy));
		mobiles.shrink_to_fit();
#ifdef _DEBUG
		cout << "Mobile Object got deleted" << endl;
#endif
	}

	delete objectToDestroy;
}

void ObjectHandler::SpawnObject()
{
	for (auto object : objects)
		object->SetAlive(true);
}

void ObjectHandler::CleanUp()
{
	if (objects.size())
	{
		/*for (auto object : objects) 
		{
			graphicEngine::Instance().DestroyAnimationInstance(object);
		}*/
		for (unsigned int i = 0; i < objects.size(); i++) 
		{
			DestroyObject(objects[i]);
		}
	}
	objects.shrink_to_fit();

}


std::vector <GameObject*>::iterator ObjectHandler::GetIterator(GameObject * object)
{
	return std::find(objects.begin(), objects.end(), object);
}

std::vector <NPC*>::iterator ObjectHandler::GetNPCIterator(GameObject * npc)
{
	return std::find(NPCs.begin(), NPCs.end(), npc);
}

std::vector <MobileObject*>::iterator ObjectHandler::GetMobileObjectIterator(GameObject * mobile)
{
	return std::find(mobiles.begin(), mobiles.end(), mobile);
}

void ObjectHandler::Update()
{
	for (unsigned int i = 0; i < objects.size();  i++)
	{
		if (objects[i]->IsAlive())
		{
			objects[i]->Update();
		}
		else
			DestroyObject(objects[i]);
	}

	for (unsigned int i = 0; i < objects.size(); i++)
		if (!objects[i]->IsAlive())
			DestroyObject(objects[i]);
	
	//movement update
	for (auto mobile : mobiles)
		for (int i = 0; i < mobile->GetVelocity(); i++)
			if (mobile->IsAlive())
				mobile->Move();

}

void ObjectHandler::ClearTargets()
{
	for (auto NPC : NPCs)
		NPC->SetTarget(nullptr);
}

template void ObjectHandler::CreateObject<Yeti>(float x, float y);
template void ObjectHandler::CreateObject<Player>(float x, float y); //it is needed, without it we get unrsolved link external 2019 -_-
template void ObjectHandler::CreateObject<StaticObject>(float x, float y);

template void ObjectHandler::DestroyObject<Character>(Character *objectToDestroy);