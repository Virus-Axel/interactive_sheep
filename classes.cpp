#include "classes.h"

float distance(float x1, float x2, float y1, float y2){
	return(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}
float angle(float x1, float x2, float y1, float y2){
	if(x2 > x1)
		return(atan((y2-y1)/(x2-x1))-1.57);
	else
		return(atan((y2-y1)/(x2-x1))+1.57);
}
force_field::force_field(){
	x = (float)(rand()%1000)/1000;
	y = (float)(rand()%1000)/1000;
	strength = (float)(rand()%1000)/1000;
	intensity = 1.0f;
	layer = rand()%10;
}
force_field::force_field(float x, float y, float strength, float intensity, int layer){
	this->x = x;
	this->y = y;
	this->intensity = intensity;
	this->strength = strength;
	this->layer = layer;
}
force_field::~force_field(){
	
}
particle::particle(){
	//this->ax = (float)(rand()%1000)/1000;
	//this->ay = (float)(rand()%1000)/1000;
	this->ax = 0;
	this->ay = 0;
	x = (float)(rand()%1000)/1000;
	y = (float)(rand()%1000)/1000;
	r = (float)(rand()%1000)/1000;
	g = (float)(rand()%1000)/1000;
	b = (float)(rand()%1000)/1000;
	//layer = rand()%10;
	layer = 1;
}
particle::particle(float x, float y, float r, float g, float b, float a, int layer){
	//this->ax = (float)(rand()%1000)/1000;
	//this->ay = (float)(rand()%1000)/1000;
	this->ax = 0;
	this->ay = 0;
	this->x = x;
	this->y = y;
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
	this->layer = layer;
}
bool particle::handle(std::vector<force_field>& forces){
	for(unsigned int c = 0; c < forces.size(); c++){
		if(distance(x, forces[c].x, y, forces[c].y) < forces[c].strength && layer == forces[c].layer){
				ax += forces[c].intensity*sin(angle(x, forces[c].x, y, forces[c].y))*(forces[c].strength-distance(x, forces[c].x, y, forces[c].y))/5000.0f;
				ay -= forces[c].intensity*cos(angle(x, forces[c].x, y, forces[c].y))*(forces[c].strength-distance(x, forces[c].x, y, forces[c].y))/5000.0f;
		}
	}
	x += ax;
	y += ay;
	if(x < -2.0f || x > 3.0f || y < -2.0f || y > 3.0f){
		return 1;
	}
	return 0;
}
particle::~particle(){
	
}
