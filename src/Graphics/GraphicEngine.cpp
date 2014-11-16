#include "../GameEngine.h"
//#include "GraphicEngine.h"
#include "UI/UI_GraphicalElement.h"
#include <iostream>

GraphicEngine::GraphicEngine()
{
	al_init_primitives_addon();
	al_init_image_addon();
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

	//GameObjectsMap.push_back(std::make_pair(object, nullptr));

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
	//tbi
}

void GraphicEngine::DefineUI_Element_Graphic(string elementsClassName, std::vector<ALLEGRO_BITMAP *> bitmaps)
{
	UI_elementsGraphicsMap.emplace(elementsClassName, bitmaps);
}

void GraphicEngine::CreateUI_Element_GraphicInstance(UI_element *element)
{
	//creating a base for Graphical Element, actually idk whether it is actually that neccessary to have
	//UI_GraphicalElement *UI_graphicalElement;
	//UI_graphicalElement = new UI_GraphicalElement();

	//getting the class name
	const std::type_info& info = typeid(*element); //epic motherfucking win
	string className = static_cast<string>(info.name());

	//cout << "name of object is: " << className << endl;

	//UI_elementsMap.push_back(std::make_pair(element, nullptr));

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
			currentPair = &elem;
	}

	if (currentPair != nullptr)
	{
		//setting default graphic
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
	for (auto &UIElement : UI_elementsMap)
	{
		if (UIElement.second != nullptr && UIElement.first->isVisible())
			al_draw_bitmap(UIElement.second, (UIElement.first->GetX() - (UIElement.first->GetWidth() / 2)),
			(UIElement.first->GetY() - (UIElement.first->GetHeight() / 2)), 0);
	}

	for (auto &Gobject : GameObjectsMap)
	{
		//some animation algorithm
	}
}