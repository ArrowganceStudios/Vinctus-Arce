#include "Camera.h"
#include "../../Globals.h"
#include "../Player.h"


Camera::Camera()
{
	mapBitmap = nullptr;


	mapWidth = 0;
	mapHeight = 0;
}

void Camera::Init(GameObject * object)
{
	mapBitmap = graphicEngine::Instance().GetMapBitmap();

	mapWidth = al_get_bitmap_width(mapBitmap);
	mapHeight = al_get_bitmap_height(mapBitmap);

	actor = object;

	center.x = actor->GetX();
	center.y = actor->GetY();

}

bool Camera::CanGoUp()
{
	return (topLeftCorner.y >= 0);
}

bool Camera::CanGoDown()
{
	return (bottomRightCorner.y <= mapHeight);
}

bool Camera::CanGoLeft()
{
	return (topLeftCorner.x >= 0);
}
bool Camera::CanGoRight()
{
	return (bottomRightCorner.x <= mapWidth);
}

void Camera::Update()
{
	if (actor->GetX() > SCREEN_WIDTH / 2 && actor->GetX() < mapWidth - SCREEN_WIDTH / 2)
		target.x = actor->GetX();
	if (actor->GetY() > SCREEN_HEIGHT / 2 && actor->GetY() < mapHeight - SCREEN_HEIGHT / 2)
		target.y = actor->GetY();

		center.x += ((target.x - center.x) * 0.05);
		center.y += ((target.y - center.y) * 0.05);
}

void Camera::CalculateCamera()
{
	//if (center.x > SCREEN_WIDTH / 2 && center.x < mapWidth - SCREEN_WIDTH / 2)	
		topLeftCorner.x = center.x - SCREEN_WIDTH / 2;
	//if (center.y > SCREEN_HEIGHT / 2 && center.y < mapHeight - SCREEN_HEIGHT / 2)	
		topLeftCorner.y = center.y - SCREEN_HEIGHT / 2;
}