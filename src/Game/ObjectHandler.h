#pragma once
#include <vector>
#include "../Globals.h"


class GameObject;
class ObjectHandler
{
private:
	static ObjectHandler *objectHandler;
	std::vector <GameObject *> objects;
	ObjectHandler();
	~ObjectHandler() { if (objectHandler != NULL) delete objectHandler; }
public:
	template <class Type> 
	void CreateObject();

	void Debug();
	void ObjectHandler::CleanUp();

	template <class Type>
	void DestroyObject(const Type *objectToDestroy);

	static ObjectHandler& GetObjectHandler()
	{
		if (objectHandler == NULL) objectHandler = new ObjectHandler(); //lazy initialization of one instance
		return *objectHandler;
	}

	

};


