#pragma once
#include <vector>
//#include "../Globals.h"
#include "../Singleton.h"




class GameObject;
class ObjectHandler : public Singleton <ObjectHandler>
{
private:
	friend Singleton < ObjectHandler > ;
	std::vector <GameObject *> objects;
protected:
	ObjectHandler();
public:
	template <class Type> 
	void CreateObject();

	template <class Type>
	void DestroyObject(const Type *objectToDestroy);

	void SpawnObject();
	void ObjectHandler::CleanUp();


	/*static ObjectHandler& GetObjectHandler()
	{
		if (objectHandler == NULL) objectHandler = new ObjectHandler(); //lazy initialization of one instance
		return *objectHandler;
	}*/


};


