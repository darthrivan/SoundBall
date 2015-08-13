//
//  Particle.cpp
//  SoundBall
//
//  Created by blag on 11/08/15.
//
//

//#include <GLUT/glut.h>
//#include <cmath>

//#include "ofMath.h"
//#include "ofGraphics.h"
#include "Particle.h"


Particle::Particle() {
    radius = 150;
    theta = 0;
    u = 0;
    vTheta = 0;
    vU = 0;
}

Particle::Particle(float _theta, float _u) {
    radius = 150;
    theta = _theta;
    u = _u;
    vTheta = 0;
    vU = 0;
}

Particle::Posi Particle::getPosition() {
    Posi ret;
    ret.x = x;
    ret.y = y;
    ret.z = z;
    return ret;
}

void Particle::update() {
    vTheta += ofRandom(-0.001,0.001);
    theta += vTheta;
    
    if (theta<0||theta>TWO_PI) {
        vTheta*=-1;
    }
    
    vU += ofRandom(-0.001,0.001);
    u += vU;
    
    if (u<-1||u>1) vU*=-1;
    
    vU *= 0.95;
    vTheta *= 0.95;
    
    x = radius*cos(theta)*sqrt(1-(u*u));
    y = radius*sin(theta)*sqrt(1-(u*u));
    z = radius*u;
}

void Particle::draw() {
    ofPushMatrix();
    ofTranslate(x,y,z);
    //glutSolidSphere(3, 6, 6);
    ofCircle(x, y, z, 1);
    ofPopMatrix();
}