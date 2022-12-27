#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <random>
#include "SierpinskiGasket.h"

SierpinskiGasket::SierpinskiGasket(){

	// set initial triangle points
	this->initial_triangle.points[0].x = -0.5f;
	this->initial_triangle.points[0].y = -0.5f;

	this->initial_triangle.points[1].x = 0.0f;
	this->initial_triangle.points[1].y = 0.5f;

	this->initial_triangle.points[2].x = 0.5f;
	this->initial_triangle.points[2].y = -0.5f;

	// get an initial random point inside a triangle
	this->initial_random_point_inside_triangle = this->random_point_inside_a_triangle();
	// setup the initial value of the last point
	this->last_point = this->initial_random_point_inside_triangle;
}

float SierpinskiGasket::random_point() {
	float random_point = -1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2)));
	return random_point;
}

void SierpinskiGasket::draw() {

	glBegin(GL_TRIANGLES);
	for (int i = 0; i <= 2; i++) {
		glVertex2f(this->initial_triangle.points[i].x, this->initial_triangle.points[i].y);
	}
	glEnd();
	
	this->list_of_points.push_back(this->get_a_new_point());
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	for (Point p : this->list_of_points) {
		glVertex2f(p.x, p.y);
	}
	glEnd();
	glColor3f(1.0f, 1.0f, 1.0f);

}

Point SierpinskiGasket::random_point_inside_a_triangle()
{
	Point random_point;
	float r1 = static_cast<float> (rand()) / static_cast<float> (RAND_MAX);
	float r2 = static_cast<float> (rand()) / static_cast<float> (RAND_MAX);
	
	// track if the point would be inside or outside the triangle.
	bool inside = r1 + r2 <= 1;
	
	// get A vector p1->p2
	Point vector_A = this->get_vector_from_points(this->initial_triangle.points[0].x, this->initial_triangle.points[0].y, this->initial_triangle.points[1].x, this->initial_triangle.points[1].y);
	// get B vector p1->p3
	Point vector_B = this->get_vector_from_points(this->initial_triangle.points[0].x, this->initial_triangle.points[0].y, this->initial_triangle.points[2].x, this->initial_triangle.points[2].y);

	// inverse point if outside the triangle
	if (r1 + r2 > 1) {
		r1 = 1-r1;
		r2 = 1-r2;
	}

	// calculate random point x and y
	Point vector_U;
	vector_U.x = r1 * vector_A.x;
	vector_U.y = r1 * vector_A.y;

	Point vector_V;
	vector_V.x = r2 * vector_B.x;
	vector_V.y = r2 * vector_B.y;

	random_point.x = vector_U.x + vector_V.x;
	random_point.y = vector_U.y + vector_V.y;

	// move from first point
	random_point.x = random_point.x + this->initial_triangle.points[0].x;
	random_point.y = random_point.y + this->initial_triangle.points[0].y;

	// return the new value
	return random_point;
}

Point SierpinskiGasket::get_a_new_point()
{
	Point new_point;

	// get random point from the initial triangle points
	int triangle_point = rand() % 3;

	// calculate the new_point
	// find the vector from triangle point to last point then devide by two => lerp
	Point new_vector = this->get_vector_from_points(this->initial_triangle.points[triangle_point].x, this->initial_triangle.points[triangle_point].y, this->last_point.x, this->last_point.y);
	// divide the vector by half
	new_vector.x = new_vector.x * 0.5f;
	new_vector.y = new_vector.y * 0.5f;

	// calculate the new point  points from the triangle point
	new_point.x = new_vector.x + this->initial_triangle.points[triangle_point].x;
	new_point.y = new_vector.y + this->initial_triangle.points[triangle_point].y;

	// set the the new point to be the last point
	this->last_point = new_point;

	return new_point;
}

Point SierpinskiGasket::get_vector_from_points(float p1_x, float p1_y, float p2_x, float p2_y)
{
	Point vector;
	vector.x = p2_x - p1_x;
	vector.y = p2_y - p1_y;
	return vector;
}


