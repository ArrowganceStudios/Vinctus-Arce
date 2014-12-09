#include "Slider.h"
#include "../Globals.h"


Slider::Slider(float x, float y, int numberOfSliderPositions) : x(x), numberOfSliderPositions(numberOfSliderPositions), y(y) 
{
	positions = new int(numberOfSliderPositions);
	const int offset = SliderDimension::sliderBarWidth / (numberOfSliderPositions - 1);
	/*for (int i = 0; i < numberOfSliderPositions; i++)
		positions[i] = i*offset;          <---- to be changed*/
}

