#include "../GameEngine.h"
#include <iostream>

GraphicEngine::GraphicEngine()
{
	al_init_primitives_addon();
	al_init_image_addon();

	textManager = new TextManager();
}

void GraphicEngine::DefineAnimation(string objectsClassName, std::vector<Sprite *> animations)
{
	GameObjectsAnimationsMap.emplace(objectsClassName, animations);
}

void GraphicEngine::CreateGraphicInstance(GameObject *object) 
{
	//getting the class name
	const std::type_info& info = typeid(object);
	string className = static_cast<string>(info.name());

	cout << className;
	//setting default sprite
	for (auto &graphMap : GameObjectsAnimationsMap)
	{
		if (graphMap.first == className)
		{
			GameObjectsMap.push_back(std::make_pair(object, graphMap.second.at(0)));
			break;
		}
	}
}

void GraphicEngine::RequestAnimation(GameObject *gameObject, int animationNumber)
{
	//getting name of the class of object passed
	const std::type_info& info = typeid(*gameObject);
	string className = static_cast<string>(info.name());

	std::pair<GameObject *, Sprite *> *currentPair = nullptr;

	//searching for the object in a GameObjectsMap
	for (auto &elem : GameObjectsMap)
	{
		if (elem.first == gameObject)
		{
			currentPair = &elem;
			break;
		}
	}

	if (currentPair != nullptr)
	{
		for (auto &gameObjectAnimation : GameObjectsAnimationsMap) //searching for animation
		{
			if (gameObjectAnimation.first == className)
			{
				currentPair->second = gameObjectAnimation.second.at(animationNumber); //changing its animation to indicated one
				break;
			}
		}
	}
}

void GraphicEngine::DefineUIElement_Graphic(string elementsClassName, string pathName)
{
	ALLEGRO_BITMAP *newBitmap = al_load_bitmap(pathName.c_str()); //c_str() is used to convert to the const char

	if (UIElementsGraphicsMap.find(elementsClassName) != UIElementsGraphicsMap.end()) //if the class already exists
	{
		UIElementsGraphicsMap[elementsClassName].push_back(newBitmap); //then add bitmap to it
		return;
	}
	//else
	vector <ALLEGRO_BITMAP *> newBitmapVector = { newBitmap }; //make a vector of bitmap(s)
	UIElementsGraphicsMap.emplace(elementsClassName, newBitmapVector); //and create a new element in map
}

void GraphicEngine::DefineUIElement_Graphic(string elementsClassName, ALLEGRO_BITMAP *bitmap)
{
	if (UIElementsGraphicsMap.find(elementsClassName) != UIElementsGraphicsMap.end()) //if the class already exists
	{
		UIElementsGraphicsMap[elementsClassName].push_back(bitmap); //then add bitmap to it
		return;
	}
	//else
	vector <ALLEGRO_BITMAP *> newBitmapVector = { bitmap }; //make a vector of bitmap(s)
	UIElementsGraphicsMap.emplace(elementsClassName, newBitmapVector); //and create a new element in map
}

void GraphicEngine::CreateUIElement_GraphicInstance(UIElement *element)
{
	//getting the class name
	const std::type_info& info = typeid(*element);
	string className = static_cast<string>(info.name());

	//setting default graphic
	for (auto &graphMap : UIElementsGraphicsMap)
	{
		if (graphMap.first == className)
		{
			UIElementsMap.push_back(std::make_pair(element, graphMap.second.at(0)));
			break;
		}
	}
}

void GraphicEngine::RequestUIElement_Graphic(UIElement *element, int graphicNumber)
{
	const std::type_info& info = typeid(*element);
	string className = static_cast<string>(info.name());

	std::pair<UIElement *, ALLEGRO_BITMAP *> *currentPair = nullptr;

	for (auto &elem : UIElementsMap)
	{
		if (elem.first == element)
		{
			currentPair = &elem;
			break;
		}
	}

	if (currentPair != nullptr)
	{
		for (auto &graphMap : UIElementsGraphicsMap)
		{
			if (graphMap.first == className)
			{
				currentPair->second = graphMap.second.at(graphicNumber);
				break;
			}
		}
	}
}

void GraphicEngine::Render()
{
	for (auto &Gobject : GameObjectsMap)
	{
		//some animation algorithm
	}
	for (int i = 0; i < 3; i++)
	{
		for (auto &UIElement : UIElementsMap)
		{
			if (UIElement.second != nullptr && UIElement.first->isVisible() && UIElement.first->GetZ() == i)
				al_draw_bitmap(UIElement.second, (UIElement.first->GetX() - (UIElement.first->GetWidth() / 2)),
				(UIElement.first->GetY() - (UIElement.first->GetHeight() / 2)), 0);
		}
	}
}

void GraphicEngine::DestroyUIElementGraphicInstance(UIElement *element)
{
	vector<std::pair<UIElement *, ALLEGRO_BITMAP *>>::iterator pos = UIElementsMap.begin();
	for (auto &UIElement : UIElementsMap)
	{
		
		if (UIElement.first == element)
		{
			UIElementsMap.erase(pos);
			break;
		}
		pos++;
	}
}

void GraphicEngine::DestroyUIElementGraphic(string className)
{
	for (auto &graphMap : UIElementsGraphicsMap)
	{
		if (graphMap.first == className)
		{
			for (auto bitmap : graphMap.second)
			{
				al_destroy_bitmap(bitmap);
			}
			break;
		}
	}
}

void GraphicEngine::CleanUpUIMaps()
{
	UIElementsGraphicsMap.clear();

	UIElementsMap.clear();
	UIElementsMap.shrink_to_fit();
}

void GraphicEngine::Destroy()
{
	for (auto &graphMap : UIElementsGraphicsMap)
	{
		for (auto bitmap : graphMap.second)
		{
			if(bitmap != nullptr) al_destroy_bitmap(bitmap);
		}
	}
	CleanUpUIMaps();
}