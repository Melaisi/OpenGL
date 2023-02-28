#include "Point.h"

MO::Point::Point() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

MO::Point::Point(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
