#include "Particle.h"

Particle::Particle() {
}


Particle::~Particle() {
}

void Particle::setup(float width, float height) {
  position.set(ofRandom(width) - width / 2, ofRandom(height) - height / 2, ofRandom(200) - 10);
  color.set(1, 0.2, 0.2);
  r = ofRandom(1, 5);
}

void Particle::update(float x, float y, float t) {
  
  ofVec3f mouse(x, y, 0);
  
  acceleration = mouse - position;
  float length = acceleration.length();
  acceleration.normalize();
  acceleration *= sqrt(length * r / 1000);
  
  float rad = t / 40 / 180 * PI * 100;
  color.setHsb(
    ofMap(sin(rad + length / 10 / 180 * PI), -1, 1, 0, 1),
    ofMap(sin(rad / 10), -1, 1, 0, 1),
    ofMap(cos(rad / 20), -1, 1, 0.3, 1)
  );
  
  velocity += acceleration;
  velocity.limit(16);
  position += velocity;
}

void Particle::accelerate() {
}
