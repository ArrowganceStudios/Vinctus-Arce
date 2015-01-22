#include "ObjectHandler.h"
#include "MobileObject.h"
#include "Yeti.h"
#include "StaticObject.h"
#include "../Globals.h"
#include "allegro5\allegro.h"
#include <iostream>


//ObjectHandler* ObjectHandler::instance = nullptr; //this definition is needed, without it we get unrsolved link external 2001

ObjectHandler::ObjectHandler()
{

}

template<class Type> void ObjectHandler::CreateObject(float x, float y)	
{
	float width = al_get_bitmap_width(graphicEngine::Instance().GetMapBitmap());
	float height = al_get_bitmap_height(graphicEngine::Instance().GetMapBitmap());

	if (std::is_same<Type, Player>::value)
	{
		Player *object = new Player();
		object->Init(x, y, 3);
		objects.push_back(object);

		camera::Instance().Init(object);
	}
	else if (std::is_same<Type, Yeti>::value)
	{
		Yeti *object = new Yeti();
		object->Init(x, y, 1);
		objects.push_back(object);
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
		for (auto object : objects) 
		{
			graphicEngine::Instance().DestroyAnimationInstance(object);
		}
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

void ObjectHandler::Update()
{
	for (int i = 0; i < objects.size();  i++)
	{
		if (!objects[i]->IsAlive())
			DestroyObject(objects[i]);
	}
	for (auto object : objects)
		object->Update();
}

template void ObjectHandler::CreateObject<Yeti>(float x, float y);
template void ObjectHandler::CreateObject<Player>(float x, float y); //it is needed, without it we get unrsolved link external 2019 -_-
template void ObjectHandler::CreateObject<StaticObject>(float x, float y);

template void ObjectHandler::DestroyObject<Character>(Character *objectToDestroy);