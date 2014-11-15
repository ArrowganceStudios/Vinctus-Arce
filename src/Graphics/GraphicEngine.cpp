#include "../GameEngine.h"
//#include "GraphicEngine.h"
#include "UI/UI_GraphicalElement.h"

GraphicEngine::GraphicEngine()
{
	al_init_primitives_addon();
}

void GraphicEngine::DefineAnimation(string objectsClassName, std::vector<Sprite *> animations)
{
	//tbi <- some 2d array storing Game Objects and their list of animations
	GameObjectsAnimationsMap.emplace(objectsClassName, animations); //not sure whether I should use typeid(*gobject) or (gobject)
}

void GraphicEngine::CreateGraphicInstance(GameObject *object) 
{
	//getting the class name
	const std::type_info& info = typeid(object);
	string className = static_cast<string>(info.name());

	GameObjectsMap.emplace(object, nullptr);

	//setting default sprite
	for (auto &graphMap : GameObjectsAnimationsMap)
	{
		if (graphMap.first == className)
		{
			GameObjectsMap[object] = graphMap.second.at(0);
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
	const std::type_info& info = typeid(element);
	string className = static_cast<string>(info.name());

	UI_elementsMap.emplace(element, nullptr);

	//setting default graphic
	for (auto &graphMap : UI_elementsGraphicsMap)
	{
		if (graphMap.first == className)
		{
			UI_elementsMap[element] = graphMap.second.at(0); //if this ain't gonna work I'm gonna keel myself
			break;
		}
	}
}

void GraphicEngine::RequestUI_Element_Graphic(UI_element *element, int graphicNumber)
{

}

void GraphicEngine::Render()
{
	for (auto &UIElement : UI_elementsMap)
	{
		al_draw_bitmap(UIElement.second, (UIElement.first->GetX() - (UIElement.first->GetWidth() / 2)),
			(UIElement.first->GetY() - (UIElement.first->GetHeight() / 2)), 0);
	}

	for (auto &Gobject : GameObjectsMap)
	{
		//some animation algorithm
	}
	//al_draw_line(1, 2, 50, 60, al_map_rgb(255, 0, 255), 2);
}