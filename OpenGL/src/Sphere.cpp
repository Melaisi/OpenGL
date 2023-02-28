// This class header
#include "Sphere.h"

// GL needed headers
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
	// setup x-axis and y-axis with white colors
	// Use white lines
	glColor3f(1.0f, 1.0f, 1.0f);
	// x-axis
	glBegin(GL_LINES);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(1.0f, 0.0f);
	glEnd();
	// y-axis
	glBegin(GL_LINES);
	glVertex2f(0.0f, -1.0f);
	glVertex2f(0.0f, 1.0f);
	glEnd();

	for (int i = 0; i < 1000000; i++) {
		
		glColor3f(this->points[i].color.r, this->points[i].color.g, this->points[i].color.b);
		glBegin(GL_POINTS);

		// Scale the points values by 0.5 to draw them at half the space.
		glVertex3f(this->points[i].x/2, this->points[i].y/2 , this->points[i].z / 2);
		if (this->print_once) {
			//std::cout << "(" << this->points[i].x << ", " << this->points[i].y << ")\n";
		}
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

	// Y = sin(x) where x:{-1<x<+1}
	// Using radian, we can scale the screen cordinate by 180
	for (float x = -1.0f * 180.0f; x <= 1.0f * 180.0f; x += 1) {
		float rad_x = x * degrees_to_float;
		// x value need to be converted back to screen coordinate
		this->points[points_index].x = x / 180;
		this->points[points_index].y = sinf(rad_x);
		this->points[points_index].color = color_red;
		points_index++;
	}
	// Y = cos(x) where x:{-1<x<+1}
	// Using radian, we can scale the screen cordinate by 180
	for (float x = -1.0f * 180.0f; x <= 1.0f * 180.0f; x += 1) {
		float rad_x = x * degrees_to_float;
		// x value need to be converted back to screen coordinate
		this->points[points_index].x = x / 180;
		this->points[points_index].y = cosf(rad_x);
		this->points[points_index].color = color_green;
		points_index++;
	}

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

	//// X = sin(y) where y:{-1<y<+1}
	//// Using radian, we can scale the screen cordinate by 180
	//float i = 0.2f;
	//for (float y = -1.0f * 180.0f; y <= 1.0f * 180.0f; y += 1.0f) {
	//	float rad_y = pi * (y / 180);
	//	this->points[points_index].x = sinf(rad_y);
	//	// y value need to be converted back to screen coordinate
	//	//std::cout << y / 180 << std::endl;
	//	this->points[points_index].y =  y/180;
	//	this->points[points_index].color = color_orange;
	//	points_index++;
	//	//i += 0.001f;
	//}
	//
	//// X = cos(y) where y:{-1<y<+1}
	//// Using radian, we can scale the screen cordinate by 90
	//for (float y = -1.0f * 180.0f; y <= 1.0f * 180.0f; y += 1) {
	//	float rad_y = pi * (y / 180);
	//	this->points[points_index].x = cosf(rad_y);
	//	// y value need to be converted back to screen coordinate
	//	this->points[points_index].y =  y / 180;
	//	this->points[points_index].color = color_yellow;
	//	points_index++;
	//}

	//// Y = sin(x).cos(x) where x:{-1<x<+1}
	//// Using radian, we can scale the screen cordinate by 180
	//for (float x = -1.0f * 180.0f; x <= 1.0f * 180.0f; x += 1) {
	//	float rad_x = pi * (x / 180);
	//	// x value need to be converted back to screen coordinate
	//	this->points[points_index].x = x / 180;
	//	this->points[points_index].y = sinf(rad_x)*cosf(rad_x);
	//	this->points[points_index].color = color_blue;
	//	points_index++;
	//}

	//// Y = sin(x).cos(x) where x:{-1<x<+1}
	//// X = sin(x)
	//// Using radian, we can scale the screen cordinate by 180
	//for (float x = -1.0f * 180.0f; x <= 1.0f * 180.0f; x += 1) {
	//	float rad_x = pi * (x / 180);
	//	// x value need to be converted back to screen coordinate
	//	this->points[points_index].x = sinf(rad_x);
	//	this->points[points_index].y = sinf(rad_x) * cosf(rad_x);
	//	//std::cout << "x: " << x << "\trad_X:" << rad_x << "\tsinf(rad_x):" << sinf(this->points[points_index].x) << "\tsinf(rad_x)*cosf(rad_x):" << this->points[points_index].y << std::endl;
	//	this->points[points_index].color = color_white;
	//	points_index++;
	//}

	//// Y = sin(x).cos(x) where x:{-1<x<+1}
	//// X = sin(x)
	//// Using radian, we can scale the screen cordinate by 180
	//for (float x = -1.0f * 180.0f; x <= 1.0f * 180.0f; x += 1) {
	//	float rad_x = pi * (x / 180);
	//	// x value need to be converted back to screen coordinate
	//	this->points[points_index].x = sinf(rad_x) * cosf(rad_x);
	//	this->points[points_index].y = sinf(rad_x) * cosf(rad_x);
	//	this->points[points_index].color = color_white;
	//	points_index++;
	//}

	// Y = sin(x).cos(x) where x:{-1<x<+1}
	// X = sin(x)
	// Using radian, we can scale the screen cordinate by 180
	//for (float x =-180; x <= 180.0f; x += 1) {
	//	float rad_x = PI * (x / 180);
	//	// x value need to be converted back to screen coordinate
	//	this->points[points_index].x = sinf(rad_x)* cosf(rad_x);
	//	this->points[points_index].y = (x / 180);
	//	this->points[points_index].color = color_white;
	//	points_index++;
	//}

	// set sin(x) where x0 = -180 to +180 with 20 steps

	// use red color for these points
	//red = 1.0f;
	//green = 0.0f;
	//blue = 0.0f;

	//// draw the values at y=0
	//y = 0.0f;

	//std::cout << "\nsinf(theta):";
	//for (float theta = -180.0f; theta <= 180.0f; theta += 20) {
	//	x = sinf(theta);
	//	std::cout << "\nnsinf(" << theta << ") = " << x;
	//	this->points[points_index].x = x;
	//	this->points[points_index].y = y;
	//	this->points[points_index].red = red;
	//	this->points[points_index].green = green;
	//	this->points[points_index].blue = blue;

	//	points_index++;
	//}

	// set cos(x) where x0 = -80 to +80 with 20 steps

	// use yellow color for these points
	//red = 1.0f;
	//green = 1.0f;
	//blue = 0.0f;

	//// draw the values at y = 0.2f
	//y = 0.2f;

	//std::cout << "\ncosf(phi):";
	//for (float phi = -80.0f; phi <= 80.0f; phi += 20) {
	//	x = cosf(phi);
	//	std::cout << "\ncosf(" << phi << ") = " << x;
	//	this->points[points_index].x = x;
	//	this->points[points_index].y = y;
	//	this->points[points_index].red = red;
	//	this->points[points_index].green = green;
	//	this->points[points_index].blue = blue;

	//	points_index++;
	//}

	// set x = sin(theta) * cos(phi)

	// use white color for these points
	//red = 1.0f;
	//green = 1.0f;
	//blue = 1.0f;

	//// draw the values at y = -0.2f
	//y = -0.2f;

	//std::cout << "\nsin(theta) * cosf(phi):";
	//for (float phi = -80.0f; phi <= 80.0f; phi += 20) {
	//	for (float theta = -180.0f; theta <= 180.0f; theta += 20) {
	//		// x = sin(theta) * cos(phi)
	//		x = sinf(theta) * cosf(phi);
	//		std::cout << "\nsinf(" << theta << ")*cosf(" << phi << ") = " << x;
	//		this->points[points_index].x = x;
	//		this->points[points_index].y = y;
	//		this->points[points_index].red = red;
	//		this->points[points_index].green = green;
	//		this->points[points_index].blue = blue;

	//		points_index++;
	//	}
	//}

	// draw multiple function for x = i; where i = -180 to +180 

	//for (float i = -1.0f; i <= 1.0f; i += 0.1f) {
	//	std::cout << i;
	//	this->points[points_index].x = i;
	//	this->points[points_index].y = 1;
	//	this->points[points_index].red = 0.0f;
	//	this->points[points_index].green = 1.0f;
	//	this->points[points_index].blue = 0.0f;
	//	points_index++;
	//}

	// x = -1 , +1
	// y = sin(x)
	/*float deg = 0.0f;
	for (float i = -1.0f; i <= 1.0f; i += 0.01f) {
		std::cout << sinf(deg) <<std::endl;
		this->points[points_index].x = i;
		this->points[points_index].y = sinf(deg);
		this->points[points_index].red = 0.5f;
		this->points[points_index].green = 0.5f;
		this->points[points_index].blue = 0.5f;
		points_index++;
		deg = fmodf(deg = deg+1, 360.0f);
		std::cout << "\ndeg: "<< deg << std::endl;
	}*/

	

	/*for (float i = 0.0f; i <= 360.0f; i++) {
		float rad = (i / 180) * pi;
		this->points[points_index].x = i/360;
		this->points[points_index].y = sinf(rad);
		this->points[points_index].red = 1.0f;
		this->points[points_index].green = 1.0f;
		this->points[points_index].blue = 0.0f;
		points_index++;
	}

	for (float i = -180.0f; i <= 180.0f; i++) {
		float rad = (i / 180) * pi;
		this->points[points_index].x = i / 360;
		this->points[points_index].y = sinf(rad);
		this->points[points_index].red = 1.0f;
		this->points[points_index].green = 0.5f;
		this->points[points_index].blue = 1.0f;
		points_index++;
	}*/

	//for (float i = 0.0f; i <= 360.0f; i++) {
	//	float rad = (i / 180) * pi;
	//	this->points[points_index].x = i / 360;
	//	this->points[points_index].y = cosf(rad);
	//	this->points[points_index].red = 1.0f;
	//	this->points[points_index].green = 1.0f;
	//	this->points[points_index].blue = 1.0f;
	//	points_index++;
	//}
	
	/*for (float i = -90.0f; i <= 90.0f; i++) {
		float rad = (i / 180) * pi;
		this->points[points_index].x = i / 360;
		this->points[points_index].y = cosf(rad);
		this->points[points_index].red = 1.0f;
		this->points[points_index].green = 1.0f;
		this->points[points_index].blue = 1.0f;
		points_index++;
	}*/

	//for (float j = -90.0f; j <= 90.0f; j++) {
		/*float theta = (-50 / 180) * pi;
		for (float i = -180.0f; i <= 180.0f; i+=10) {
			float phi = (i / 180) * pi;
			this->points[points_index].x = sinf(theta) * cosf(phi);
			this->points[points_index].y = cosf(theta) * sinf(phi);
			this->points[points_index].color = color_red;
			points_index++;
			
		}*/
	//}
}