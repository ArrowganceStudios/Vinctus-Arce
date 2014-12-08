#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <vector>
//#include "../GameEngine.h"
#include "../Game/GameObject.h"
//#include "Sprite.h"
#include "UI/UIElement.h"
#include "UI/TextManager.h"
#include "../Singleton.h"
#include <map>

class GameEngine;
class TextManager;

class GraphicEngine : public Singleton<GraphicEngine>
{
	friend Singleton < GraphicEngine >;
	//maps storing animations/graphics for each type of class
	std::map <std::string, std::vector<Sprite *>> GameObjectsAnimationsMap;
	std::map <std::string, std::vector<ALLEGRO_BITMAP *>> UIElementsGraphicsMap;

	//maps storing an actual list of UI and Game objects and text instances
	std::vector <std::pair<GameObject *, Sprite *>> GameObjectsMap;
	std::vector <std::pair<UIElement *, ALLEGRO_BITMAP *>> UIElementsMap;
protected:
	GraphicEngine();
	~GraphicEngine() { if (textManager != nullptr) delete &textManager; };

public:

	TextManager *textManager;

	void Init(){}; //??
	void Render();

	void DefineAnimation(std::string objectsClassName, std::vector<Sprite *> animations);
	void CreateGraphicInstance(GameObject *object);
	void RequestAnimation(GameObject *gameObject, int animationNumber);

	void DefineUIElement_Graphic(std::string elementsClassName, std::string pathName);
	void DefineUIElement_Graphic(std::string elementsClassName, ALLEGRO_BITMAP *bitmap);
	void DestroyUIElementGraphic(std::string className);

	void CreateUIElement_GraphicInstance(UIElement *element);
	void DestroyUIElementGraphicInstance(UIElement *element);
	void RequestUIElement_Graphic(UIElement *element, int graphicNumber);

	void CleanUpUIMaps();
	void Destroy();
};