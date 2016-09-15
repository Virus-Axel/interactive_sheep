#ifndef CLASSES_H
#define CLASSES_H
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <iostream>

float distance(float x1, float y1, float x2, float y2);
class vector2{
	public:
	float x, y;
};
class force_field{
	public:
	float x, y, strength, intensity;
	int layer;
	force_field();
	force_field(float x, float y, float strength, float intensity, int layer);
	~force_field();
};
class particle{
	public:
	float x, y, r, g, b, a, ax, ay;
	int layer;
	particle();
	particle(float x, float y, float r, float g, float b, float a, int layer);
	bool handle(std::vector<force_field>& forces);
	~particle();
};
class bezier{
	public:
	vector2 p1, p2, p3, p4;
	//bezier();
	//bezier();
};
#endif
