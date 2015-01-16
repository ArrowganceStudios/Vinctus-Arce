#pragma once
#include "../../Singleton.h"
#include <allegro5\allegro.h>
#include "../GameObject.h"

struct Point
{
	float x = 0;
	float y = 0;
};

class Camera : public Singleton <Camera>
{
	friend Singleton < Camera >;
private:
	float mapWidth;
	float mapHeight;

	Point topLeftCorner;
	Point bottomRightCorner;
	Point center;

	ALLEGRO_BITMAP * mapBitmap;

	bool CanGoUp();
	bool CanGoDown();
	bool CanGoLeft();
	bool CanGoRight();

	GameObject * actor;

protected:
	Camera();
public:

	void Init(GameObject * object);

	float GetTopLeftCornerX() { return topLeftCorner.x; }
	float GetTopLeftCornerY() { return topLeftCorner.y; }

	float GetCenterX() { return center.x; }
	float GetCenterY() { return center.y; }

	void Update();

	void CalculateCamera();


};