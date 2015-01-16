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
	center.x = actor->GetX();
	center.y = actor->GetY();
}

void Camera::CalculateCamera()
{
	topLeftCorner.x = center.x - SCREEN_WIDTH / 2;
	topLeftCorner.y = center.y - SCREEN_HEIGHT / 2;
	
	bottomRightCorner.x = center.x + SCREEN_WIDTH / 2;
	bottomRightCorner.y = center.y + SCREEN_HEIGHT / 2;
}