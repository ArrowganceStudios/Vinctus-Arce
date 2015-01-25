#pragma once

struct Point
{
	float x;
	float y;

	Point() : x(0), y(0) {};
	Point(float x, float y) : x(x), y(y) {};
};

struct Circle
{
	Point center;
	int radius;

	Circle() : radius(0) 
	{ 
		center = Point(0, 0); 
	}

	Circle(float x, float y, int radius) : radius(radius) 
	{ 
		center = Point(x, y); 
	}
};

struct Rectangle
{
	Point center;
	float width;
	float height;

	Rectangle(float x, float y, float width, float height) : width(width), height(height) 
	{
		center = Point(x, y);
	}
};