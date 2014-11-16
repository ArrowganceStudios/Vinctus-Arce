#pragma once

class UI_element
{

protected:
	UI_element(float x, float y) :x(x), y(y) {};
	float height;
	float width;

	float x;
	float y;

	int z;
public:
	float GetX() const { return x; }
	float GetY() const { return y; }

	float GetHeight() const { return height; }
	float GetWidth() const { return width; }

	virtual void Polymorphic() { /*do nothing and win*/ } //this is bullshit but w/e
};