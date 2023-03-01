// In this program the sphere is projected on screen space. 
// Converting this to world space will be done in later chapters.
// Note that the sphare also need to use triangles at the top and bottom ends.

// This class header
#include "Sphere.h"

// GL headers
#include <GL/glew.h>

// Core classes
#include "Core/Point.h"
using MO::Point;
#include "Core/Color.h"
using MO::ColorRGB;

// Math standard library
#include <cmath>

// For Debugging
#include <iostream>


Sphere::Sphere() {
	initialize_points();
}

void Sphere::draw()
{
	for (int i = 0; i < 1000000; i++) {
		
		glColor3f(this->points[i].color.r, this->points[i].color.g, this->points[i].color.b);
		glBegin(GL_POINTS);

		// Scale the points values by 0.5 to draw them at half the space.
		glVertex3f(this->points[i].x/2, this->points[i].y/2 , this->points[i].z / 2);

		glEnd();
	}
	this->print_once = false;
}

void Sphere::initialize_points() {

	// used to populate the points array values
	int points_index = 0;

	// initialize color variables
	MO::ColorRGB color_black(0.0f,0.0f,0.0f);
	
	// initiaze x to define the point default x value as 0.0f
	float x = 0.0f;
	float y = 0.0f;

	// populate this class points array with zeros for x and y
	for (int i = 0; i < 1000; i++) {
		this->points[i] = Colored_Point(0.0f, 0.0f, 0.0f, color_black);
	}
	
	// Define Pi to use radian instead of degrees
	// Define PI
	const float PI = 3.14159;
	const float degrees_to_float = PI / 180.0;
	
	// Define a few color for convenience
	ColorRGB color_red = ColorRGB(1.0f, 0.0f, 0.0f);
	ColorRGB color_green = ColorRGB(0.0f, 1.0f, 0.0f);
	ColorRGB color_blue = ColorRGB(0.0f, 0.0f, 1.0f);
	ColorRGB color_yellow = ColorRGB(1.0f, 1.0f, 0.0f);
	ColorRGB color_orange = ColorRGB(1.0f, 0.5f, 0.0f);
	ColorRGB color_white = ColorRGB(1.0f, 1.0f, 1.0f);

	for (float phi = -80.0; phi <= +80.0; phi += 20.0) {
		// Convert phi from degrees to radian
		float phi_rad = phi * degrees_to_float;
		// Create another value that 20 degree a part
		float phi_rad_20 = (20 + phi) * degrees_to_float;
		// Theta describe the angle of a full circle  
		for (float theta = -180.0; theta <= 180.0; theta += 20.0) {
			// Convert theta from degrees to radian
			float theta_rad = theta * degrees_to_float;
			// scale the circle by phi curve
			this->points[points_index].x = sin(theta_rad) * cos(phi_rad);
			this->points[points_index].y = cos(theta_rad) * cos(phi_rad);
			this->points[points_index].z = sin(phi_rad);
			this->points[points_index].color = color_white;
			points_index++;
			this->points[points_index].x = sin(theta_rad) * cos(phi_rad_20);
			this->points[points_index].y = cos(theta_rad) * cos(phi_rad_20);
			this->points[points_index].z = sin(phi_rad);
			this->points[points_index].color = color_orange;
			points_index++;
		}
	}
}