#pragma once

class Slider
{
private:
	float x;
	float y;
	int  const numberOfSliderPositions;
	int currentPosition;
	int *positions;
public:
	Slider(float x, float y, int const numberOfSliderPositions);
	~Slider() { delete positions; }
	int GetSliderPosition() { return currentPosition; }

};