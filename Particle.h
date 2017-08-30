#pragma once

#include "ofMain.h"

class Particle 
{
public:
	Particle();
	Particle(ofVec3f location, int size, float r, float g, float b);
	~Particle();

	void update();
	void draw();
private:
	ofVec3f location;
	ofImage img;
	
	int size;
	float r, g, b;

	float speed;

};
