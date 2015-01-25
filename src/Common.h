#pragma once

struct Point
{
	float x;
	float y;

	Point() : x(0), y(0) {};
	Point(float x, float y) : x(x), y(y) {};
};

struct CircleType
{
	Point center;
	int radius;

	CircleType() : radius(0) 
	{ 
		center = Point(0, 0); 
	}

	CircleType(float x, float y, int radius) : radius(radius) 
	{ 
		center = Point(x, y); 
	}
};

struct RectangleType
{
	Point center;
	float width;
	float height;

	RectangleType(float x, float y, float width, float height) : width(width), height(height) 
	{
		center = Point(x, y);
	}
};

enum directions
{
	Up,
	Down,
	Left,
	Right
};