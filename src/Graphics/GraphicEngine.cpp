#include "../GameEngine.h"
#include "GraphicEngine.h"
#include "UI/UI_GraphicalElement.h"

GraphicEngine::GraphicEngine()
{
	//tbi
}
void GraphicEngine::CreateGraphicInstance(GameObject *object,int id) 
{
	
	//tbi
}

void DefineAnimation(GameObject * gameObject, std::vector<Sprite *> animations)
{
	//tbi <- some 2d array storing Game Objects and their list of animations
}

void GraphicEngine::CreateUI_Element_GraphicInstance(UI_element *element)
{
	UI_GraphicalElement *UI_graphicalElement;
	UI_graphicalElement = new UI_GraphicalElement();
	if (typeid(element) == typeid(Button))
	{
		//UI_graphicalElement->SetBitmapImage(Button::)
	}

}