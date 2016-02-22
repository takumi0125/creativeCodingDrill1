#include "ofApp.h"

const int ofApp::NUM_PARTICLES;

//--------------------------------------------------------------
void ofApp::setup(){
  ofEnableBlendMode(OF_BLENDMODE_ADD);
  ofBackground(0, 0, 0);
  
  ofDisableArbTex();
  
  img.load("particle.png");
  img.setUseTexture(false);
  
  glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
  glEnable(GL_TEXTURE_2D);
  
  shader.load("shaders/point.vert", "shaders/point.frag");

  particles = vector<Particle>(NUM_PARTICLES);
  for(int i = 0; i < NUM_PARTICLES; i++) {
    particles.push_back(*new Particle());
    particles[i].setup(ofGetWidth(), ofGetHeight());
    particles[i].update(ofGetWidth() / 2, ofGetHeight() / 2, 0);
  }
  
  mouseX = ofGetWidth() / 2;
  mouseY = ofGetHeight() / 2;
  
}

//--------------------------------------------------------------
void ofApp::update(){
  img.setUseTexture(true);
  
  vertices.resize(NUM_PARTICLES);
  colors.resize(NUM_PARTICLES);
  
  for(int i = 0; i < NUM_PARTICLES; i++) {
    particles[i].update(mouseX, mouseY, ofGetFrameNum() / 30);
    vertices[i].set(particles[i].position.x, particles[i].position.y, particles[i].position.z);
    colors[i].set(particles[i].color);
  }
  
  vbo.setVertexData(&vertices[0], NUM_PARTICLES, GL_DYNAMIC_DRAW);
  vbo.setColorData(&colors[0], NUM_PARTICLES, GL_DYNAMIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::draw(){
  shader.begin();
  ofEnablePointSprites();
  img.getTexture().bind();
  
  vbo.draw(GL_POINTS, 0, NUM_PARTICLES);
  img.getTexture().unbind();
  ofDisablePointSprites();
  
  shader.end();
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  mouseX = x;
  mouseY = y;
}


//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
  for(int i = 0; i < NUM_PARTICLES; i++) {
    particles[i].accelerate();
  }
}