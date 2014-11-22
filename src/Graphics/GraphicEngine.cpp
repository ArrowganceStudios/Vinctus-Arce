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

void GraphicEngine::DefineUI_Element_Graphic(string elementsClassName, string pathName)
{
	ALLEGRO_BITMAP *newBitmap = al_load_bitmap(pathName.c_str()); //c_str() is used to convert to the const char

	if (UI_elementsGraphicsMap.find(elementsClassName) != UI_elementsGraphicsMap.end()) //if the class already exists
	{
		UI_elementsGraphicsMap[elementsClassName].push_back(newBitmap); //then add bitmap to it
		return;
	}
	//else
	vector <ALLEGRO_BITMAP *> newBitmapVector = { newBitmap }; //make a vector of bitmap(s)
	UI_elementsGraphicsMap.emplace(elementsClassName, newBitmapVector); //and create a new element in map
}

void GraphicEngine::DefineUI_Element_Graphic(string elementsClassName, ALLEGRO_BITMAP *bitmap)
{
	if (UI_elementsGraphicsMap.find(elementsClassName) != UI_elementsGraphicsMap.end()) //if the class already exists
	{
		UI_elementsGraphicsMap[elementsClassName].push_back(bitmap); //then add bitmap to it
		return;
	}
	//else
	vector <ALLEGRO_BITMAP *> newBitmapVector = { bitmap }; //make a vector of bitmap(s)
	UI_elementsGraphicsMap.emplace(elementsClassName, newBitmapVector); //and create a new element in map
}

void GraphicEngine::CreateUI_Element_GraphicInstance(UI_element *element)
{
	//getting the class name
	const std::type_info& info = typeid(*element);
	string className = static_cast<string>(info.name());

	//setting default graphic
	for (auto &graphMap : UI_elementsGraphicsMap)
	{
		if (graphMap.first == className)
		{
			UI_elementsMap.push_back(std::make_pair(element, graphMap.second.at(0)));
			break;
		}
	}
}

void GraphicEngine::RequestUI_Element_Graphic(UI_element *element, int graphicNumber)
{
	const std::type_info& info = typeid(*element);
	string className = static_cast<string>(info.name());

	std::pair<UI_element *, ALLEGRO_BITMAP *> *currentPair = nullptr;

	for (auto &elem : UI_elementsMap)
	{
		if (elem.first == element)
		{
			currentPair = &elem;
			break;
		}
	}

	if (currentPair != nullptr)
	{
		for (auto &graphMap : UI_elementsGraphicsMap)
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
		for (auto &UIElement : UI_elementsMap)
		{
			if (UIElement.second != nullptr && UIElement.first->isVisible() && UIElement.first->GetZ() == i)
				al_draw_bitmap(UIElement.second, (UIElement.first->GetX() - (UIElement.first->GetWidth() / 2)),
				(UIElement.first->GetY() - (UIElement.first->GetHeight() / 2)), 0);
		}
	}
}

void GraphicEngine::DestroyUI_ElementGraphicInstance(UI_element *element)
{
	vector<std::pair<UI_element *, ALLEGRO_BITMAP *>>::iterator pos = UI_elementsMap.begin();
	for (auto &ui_element : UI_elementsMap)
	{
		
		if (ui_element.first == element)
		{
			UI_elementsMap.erase(pos);
			break;
		}
		pos++;
	}
}

void GraphicEngine::DestroyUI_ElementGraphic(string className)
{
	for (auto &graphMap : UI_elementsGraphicsMap)
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
	UI_elementsGraphicsMap.clear();

	UI_elementsMap.clear();
	UI_elementsMap.shrink_to_fit();
}

void GraphicEngine::Destroy()
{
	for (auto &graphMap : UI_elementsGraphicsMap)
	{
		for (auto bitmap : graphMap.second)
		{
			if(bitmap != nullptr) al_destroy_bitmap(bitmap);
		}
	}
	CleanUpUIMaps();
}