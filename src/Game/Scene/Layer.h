#pragma once

class Layer
{
	friend class Camera;
protected:
	static float x;
	static float y;
public:
	virtual void Init(){};
	virtual void Render(){};
};