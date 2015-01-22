#pragma once
#include "Graphic.h"

class AnimatedGraphic : public Graphic
{
	int animCounter;
	int curFrame;
	bool playAnimation;

public:
	AnimatedGraphic() : animCounter(0), curFrame(0), playAnimation(false) {};
	AnimatedGraphic(float h, float w) : Graphic(h, w), animCounter(0), curFrame(0), playAnimation(false) {};

	inline int GetAnimCounter() const { return animCounter; }
	inline void SetAnimCounter(int set) { animCounter = set; }
	inline void IncrementAnimCounter() { SetAnimCounter(GetAnimCounter() + 1); }

	inline int GetCurFrame() const { return curFrame; }
	inline void SetCurFrame(int set) { curFrame = set; }
	inline void IncrementCurFrame() { SetCurFrame(GetCurFrame() + 1); }

	inline void PlayAnimation() { playAnimation = true; }
	inline void StopAnimation() { playAnimation = false; }
	inline bool CanPlayAnimation() const { return playAnimation; }

	float GetDisplayedX() const;
	float GetDisplayedY() const;
};