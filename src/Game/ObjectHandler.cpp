#include "ObjectHandler.h"
#include "MobileObject.h"
#include "StaticObject.h"
#include <iostream>


//ObjectHandler* ObjectHandler::instance = nullptr; //this definition is needed, without it we get unrsolved link external 2001

ObjectHandler::ObjectHandler()
{

}

template<class Type> void ObjectHandler::CreateObject()	// shouldn't there be an argument what kind of object we want to create?
{
	
	if (std::is_same<Type, MobileObject>::value)
	{
		MobileObject *object = new MobileObject();
		objects.push_back(object);
	}
	if (std::is_same<Type, StaticObject>::value)
	{
		StaticObject *object = new StaticObject();
		objects.push_back(object);
	}
}

template<class Type> void ObjectHandler::DestroyObject(const Type *objectToDestroy)
{
	auto it = std::find(objects.begin(), objects.end(), objectToDestroy);
	objects.erase(it);
	objects.shrink_to_fit();
	delete objectToDestroy;
}

void ObjectHandler::SpawnObject()
{
	std::cout << objects.size();
}

void ObjectHandler::CleanUp()
{
	if (objects.size())
		objects.clear();
	objects.shrink_to_fit();
}

template void ObjectHandler::CreateObject<MobileObject>(); //it is needed, without it we get unrsolved link external 2019 -_-
template void ObjectHandler::CreateObject<StaticObject>();