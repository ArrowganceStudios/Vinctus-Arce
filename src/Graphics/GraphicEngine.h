#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include "AnimatedGraphic.h"
#include "StaticGraphic.h"
#include "Sprite.h"
#include "UI/TextManager.h"
#include "../Singleton.h"
#include <map>
#include <algorithm>

class TextManager;

class GraphicEngine : public Singleton<GraphicEngine>
{
	friend class Singleton < GraphicEngine > ;
protected:
	GraphicEngine();
	~GraphicEngine();

private:
	//maps storing animations/graphics for each type of class
	std::map <std::string, std::vector<Sprite *>> AnimationsMap;
	std::map <std::string, std::vector<ALLEGRO_BITMAP *>> GraphicsMap;

	//"maps" storing an actual list graphic instances
	std::vector <std::pair <AnimatedGraphic *, Sprite *>> AnimationOwnersMap;
	std::vector <std::pair <StaticGraphic *, ALLEGRO_BITMAP *>> GraphicOwnersMap;

	ALLEGRO_BITMAP * mapBitmap;

public:
	TextManager *textManager;

	void Render();

	//animations
	void DefineAnimation(std::string ownersClassName, Sprite *animation);
	void DestroyAnimation(std::string className);

	void CreateAnimationInstance(AnimatedGraphic *owner);
	void RequestAnimation(AnimatedGraphic *owner, int animationNumber);
	void DestroyAnimationInstance(AnimatedGraphic *owner);

	void DefineGraphic(std::string ownersClassName, std::string pathName);
	void DefineGraphic(std::string ownersClassName, ALLEGRO_BITMAP *bitmap);
	void DestroyGraphic(std::string className);

	//static images
	void CreateGraphicInstance(StaticGraphic *owner);
	void DestroyGraphicInstance(StaticGraphic *owner);
	void RequestGraphic(StaticGraphic *owner, int graphicID);

	void DrawAnimatedElements();
	void DrawStaticElements();
	void DrawGameMap();

	void SetMapBitmap(ALLEGRO_BITMAP * bitmap) { mapBitmap = bitmap; }
	ALLEGRO_BITMAP* GetMapBitmap() { return mapBitmap; }

	Sprite* GetSpriteFromObject(AnimatedGraphic* owner);

	void CleanUpUIMaps();
	void Destroy();

	bool IsInsideDatabase(StaticGraphic* owner);
	bool IsInsideDatabase(AnimatedGraphic* owner);
};
