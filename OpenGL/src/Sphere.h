#pragma once
#include "Drawable.h"

// Subclassing Point to add color attribute
#include "Core/Point.h"
#include "Core/Color.h"

class Colored_Point : public MO::Point {
public:

    MO::ColorRGB color = MO::ColorRGB();
    Colored_Point() : MO::Point::Point() {}
    Colored_Point(float x, float y, float z) : MO::Point::Point(this->x, this->y, this->z) {
        this->color.r = 0.0f;
        this->color.g = 0.0f;
        this->color.b = 0.0f;
    }
    Colored_Point(float x, float y, float z, MO::ColorRGB color) : MO::Point::Point(this->x, this->y, this->z) {
        this->color = color;
    }
   
};

class Sphere : public Drawable
{
public:
    Colored_Point points[1000000];
    bool print_once = true;

    Sphere();
    virtual void draw();
    void initialize_points();
};

