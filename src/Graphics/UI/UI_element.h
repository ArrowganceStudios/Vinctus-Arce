#pragma once

class UI_element
{

protected:
	UI_element(float x, float y) :x(x), y(y) { visible = false; };
	UI_element(float x, float y, float h, float w) :x(x), y(y), height(h), width(w) { visible = false; };
	float height;
	float width;

	float x;
	float y;

	int z;

	bool visible;

public:
	float GetX() const { return x; }
	float GetY() const { return y; }

	float GetHeight() const { return height; }
	float GetWidth() const { return width; }

	bool isVisible() const { return visible; }

	void Show() { visible = true; }
	void Hide() { visible = false; }

	virtual void Polymorphic() { /*do nothing and win*/ } //this is bullshit but w/e
};