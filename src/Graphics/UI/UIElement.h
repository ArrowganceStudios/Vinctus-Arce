#pragma once

class UIElement
{
protected:
	UIElement(float x, float y) :x(x), y(y) { visible = false; };
	UIElement(float x, float y, float h, float w) :x(x), y(y), height(h), width(w) { visible = false; };
	float height;
	float width;

	float x;
	float y;

	int z;

	bool visible;

public:
	float GetX() const { return x; }
	float GetY() const { return y; }

	int GetZ() const { return z; }

	float GetHeight() const { return height; }
	float GetWidth() const { return width; }

	bool isVisible() const { return visible; }

	virtual void Show() { visible = true; }

	virtual void Hide() { visible = false; }

	virtual void Polymorphic() {}
};