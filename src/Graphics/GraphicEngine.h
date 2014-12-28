#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <vector>
#include "AnimatedGraphic.h"
#include "StaticGraphic.h"
#include "Sprite.h"
#include "UI/TextManager.h"
#include "../Singleton.h"
#include <map>
#include <algorithm>

class GameEngine;
class TextManager;

class GraphicEngine : public Singleton<GraphicEngine>
{
	friend Singleton < GraphicEngine >;
	//maps storing animations/graphics for each type of class
	std::map <std::string, std::vector<Sprite *>> AnimationsMap;
	std::map <std::string, std::vector<ALLEGRO_BITMAP *>> GraphicsMap;

	//maps storing an actual list of UI and Game objects and text instances
	std::vector <std::pair<AnimatedGraphic *, Sprite *>> AnimationOwnersMap;
	std::vector <std::pair<StaticGraphic *, ALLEGRO_BITMAP *>> GraphicOwnersMap;

	//Map gameMap;
	//ViewPort viewPort;
protected:
	GraphicEngine();
	~GraphicEngine();
	public:


	TextManager *textManager;

	void Init(){}; //??
	void Render();

	void DefineAnimation(std::string ownersClassName, std::vector<Sprite *> animations);
	void CreateAnimationInstance(AnimatedGraphic *owner);
	void RequestAnimation(AnimatedGraphic *owner, int animationNumber);

	void DefineGraphic(std::string ownersClassName, std::string pathName);
	void DefineGraphic(std::string ownersClassName, ALLEGRO_BITMAP *bitmap);
	void DestroyGraphic(std::string className);

	void CreateGraphicInstance(StaticGraphic *owner);
	void DestroyGraphicInstance(StaticGraphic *owner);
	void RequestGraphic(StaticGraphic *owner, int graphicID);

	void DrawAnimatedElements();
	void DrawStaticElements();
	void DrawGameMap();

	void CleanUpUIMaps();
	void Destroy();

	bool IsInsideDatabase(StaticGraphic* owner);
	bool IsInsideDatabase(AnimatedGraphic* owner);
};