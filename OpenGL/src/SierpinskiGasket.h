#pragma once
#include <vector>



struct Point {
	float x=0.0f;
	float y=0.0f;
};

struct Triangle2D {
	Point points[3];
};

class SierpinskiGasket {
public:
	Triangle2D initial_triangle;
	std::vector<Point> list_of_points;
	Point initial_random_point_inside_triangle;
	Point last_point;

	SierpinskiGasket();
	float random_point();
	void draw();
	Point random_point_inside_a_triangle();
	Point get_vector_from_points(float p1_x,float p1_y,float p2_x,float p2_y);
	Point get_a_new_point();

	void immediate_mode_graphic();
	void retained_mode_graphic();
	void initial_draw();
	void draw_initial_triangle();
};