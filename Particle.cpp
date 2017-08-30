
#include "Particle.h"

Particle::Particle() : Particle(ofVec3f(0, 0, 0), 100, 255, 255, 255)
{

}

Particle::Particle(ofVec3f location, int size, float r, float g, float b)
{
	this->location = location;
	this->size = size;
	this->r = r;
	this->g = g;
	this->b = b;

	this->img.allocate(this->size, this->size, OF_IMAGE_COLOR);
	unsigned char* pixels = this->img.getPixels().getData();

	for (int x = 0; x < this->size; x++) {
		for (int y = 0; y < this->size; y++) {
			float distance = ((this->size / 2 - x) * (this->size / 2 - x) + (this->size / 2 - y) * (this->size / 2 - y)) / 50.f;
			if (distance == 0) { distance = 0.003; }

			int r_value = this->r / distance - 3;
			r_value = max(0, min(r_value, 255));

			int g_value = this->g / distance - 3;
			g_value = max(0, min(g_value, 255));

			int b_value = this->b / distance - 3;
			b_value = max(0, min(b_value, 255));

			pixels[x * 3 * size + y * 3 + 0] = r_value;
			pixels[x * 3 * size + y * 3 + 1] = g_value;
			pixels[x * 3 * size + y * 3 + 2] = b_value;
		}
	}

	this->img.update();

	this->speed = ofRandom(20);
}

Particle::~Particle()
{

}

void Particle::update()
{
	this->location = this->location + ofVec3f(0, this->speed, 0);

	if (this->location.y > ofGetHeight())
	{
		this->location.y = -ofGetHeight();
	}
}

void Particle::draw()
{
	ofPushMatrix();
	ofTranslate(this->location.x - this->img.getWidth() / 2, this->location.y - this->img.getHeight() / 2, this->location.z);
	ofRotateY(360 - ofGetFrameNum() % 360);

	this->img.draw(0, 0);

	ofPopMatrix();
}