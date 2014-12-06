#include "ObjectHandler.h"
#include "MobileObject.h"
#include "StaticObject.h"
#include <iostream>



ObjectHandler* ObjectHandler::objectHandler = nullptr; //this definition is needed, without it we get unrsolved link external 2001

ObjectHandler::ObjectHandler()
{

}

template<class Type> void ObjectHandler::CreateObject()
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
	delete objectToDestroy;
}

void ObjectHandler::Debug()
{
	cout << "We have " << objects.size() << " game objects" << endl;
}

void ObjectHandler::CleanUp()
{
	cout << "Doing some cleaning here, do not disturb" << endl;
	if (objects.size())
		objects.clear();
	objects.shrink_to_fit();
}

template void ObjectHandler::CreateObject<MobileObject>(); //it is needed, without it we get unrsolved link external 2019 -_-
template void ObjectHandler::CreateObject<StaticObject>();