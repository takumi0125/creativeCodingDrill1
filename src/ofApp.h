#pragma once

#include "ofMain.h"
#include "Particle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    void mousePressed(int x, int y, int button);
    void mouseMoved(int x, int y);
    void mouseEntered(int x, int y);

  
    static const int NUM_PARTICLES = 10000;
    
    ofVbo vbo;
    ofShader shader;
    ofImage img;
  
    float mouseX;
    float mouseY;
    vector<Particle> particles;
    vector<ofVec3f> vertices;
    vector<ofFloatColor> colors;
		
};
