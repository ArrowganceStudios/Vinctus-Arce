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

void Camera::Update()
{
		if (key_arrows[UP])
			center.y--;
		if (key_arrows[DOWN])
			center.y++;
		if (key_arrows[LEFT])
			center.x--;
		if (key_arrows[RIGHT])
			center.x++;
}


void Camera::CalculateCamera()
{
	topLeftCorner.x = center.x - SCREEN_WIDTH / 2;
	topLeftCorner.y = center.y - SCREEN_HEIGHT / 2;

	bottomRightCorner.x = center.x + SCREEN_WIDTH / 2;
	bottomRightCorner.y = center.y + SCREEN_HEIGHT / 2;
}