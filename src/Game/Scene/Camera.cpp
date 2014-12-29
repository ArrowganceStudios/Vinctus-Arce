#include "Camera.h"
#include "../../InputMap.h"
#include "../../Globals.h"


Camera::Camera()
{
	mapBitmap = nullptr;


	mapWidth = 0;
	mapHeight = 0;
}

void Camera::Init()
{
	mapBitmap = graphicEngine::Instance().GetMapBitmap();

	mapWidth = al_get_bitmap_width(mapBitmap);
	mapHeight = al_get_bitmap_height(mapBitmap);

	center.x = mapWidth / 2;
	center.y = mapHeight / 2;

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
		if (key_arrows[UP] && CanGoUp())		center.y -= 2;
		if (key_arrows[DOWN] && CanGoDown())	center.y += 2;
		if (key_arrows[LEFT] && CanGoLeft())	center.x -= 2;
		if (key_arrows[RIGHT] && CanGoRight())	center.x += 2;
}

void Camera::CalculateCamera()
{
	topLeftCorner.x = center.x - SCREEN_WIDTH / 2;
	topLeftCorner.y = center.y - SCREEN_HEIGHT / 2;
	
	bottomRightCorner.x = center.x + SCREEN_WIDTH / 2;
	bottomRightCorner.y = center.y + SCREEN_HEIGHT / 2;
}