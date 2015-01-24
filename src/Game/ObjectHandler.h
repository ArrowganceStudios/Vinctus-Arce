#pragma once
#include <vector>
//#include "../Globals.h"
#include "../Singleton.h"


class GameObject;
class NPC;
class Character;

class ObjectHandler : public Singleton <ObjectHandler>
{
private:
	friend Singleton < ObjectHandler > ;
	std::vector <GameObject *> objects;
	std::vector <NPC *> NPCs;
	Character* player;

protected:
	ObjectHandler();
public:
	template <class Type> 
	void CreateObject(float x = 0, float y = 0);

	template <class Type>
	void DestroyObject(Type *objectToDestroy);

	std::vector <GameObject*>::iterator GetIterator(GameObject * object);

	int GetNPCNumber() { return NPCs.size(); }

	void SpawnObject();
	void CleanUp();

	void Update();

	void ClearTargets();

};


