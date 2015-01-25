#pragma once

class Graphic
{
protected:
	int z;
	bool visible;

	float height;
	float width;

public:
	Graphic() : visible(false) {};
	Graphic(float height, float width) : height(height), width(width), visible(false) {};
	float GetWidth() const { return width; };
	float GetHeight() const { return height; };

	void SetWidth(float w) { width = w; }
	void SetHeight(float h) { height = h; }

	virtual float GetX() const { return 0; };
	virtual float GetY() const { return 0; };

	int GetZ() const { return z; }
	bool IsVisible() const { return visible; }

	virtual void Show() { visible = true; }
	virtual void Hide() { visible = false; }

};