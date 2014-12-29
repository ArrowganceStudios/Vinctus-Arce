#pragma once
#include "../../Singleton.h"
#include <allegro5\allegro.h>

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

protected:
	Camera();
public:

	void Init();

	float GetTopLeftCornerX() { return topLeftCorner.x; }
	float GetTopLeftCornerY() { return topLeftCorner.y; }

	void Update();

	void CalculateCamera();


};