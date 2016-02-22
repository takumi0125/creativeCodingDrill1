#pragma once

#include "OfMain.h"

class Particle {
  public:
    Particle();
    ~Particle();
  
    void setup(float width, float height);
    void update(float x, float y, float t);
    void accelerate();
  
    ofFloatColor color;
    ofVec3f position;
    ofVec3f velocity;
    ofVec3f acceleration;
    float r;
};