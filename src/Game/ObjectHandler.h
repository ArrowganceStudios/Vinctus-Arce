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
	void CreateObject(float x = 0, float y = 0);

	void ClearTargets();

	//template <class Type>
	void DestroyObject(GameObject *objectToDestroy);

	std::vector <GameObject*>::iterator GetIterator(GameObject * object);

	void SpawnObject();
	void CleanUp();

	void Update();


};


