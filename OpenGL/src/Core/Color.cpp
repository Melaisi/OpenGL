#include "Color.h"

MO::ColorRGB::ColorRGB()
{
	this->r = 0.0f;
	this->g = 0.0f;
	this->b = 0.0f;
}

MO::ColorRGB::ColorRGB(float red, float green, float blue)
{
	this->r = red;
	this->g = green;
	this->b = blue;
}
