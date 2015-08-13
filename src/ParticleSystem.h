//
//  ParticleSystem.h
//  SoundBall
//
//  Created by blag on 11/08/15.
//
//

#ifndef __SoundBall__ParticleSystem__
#define __SoundBall__ParticleSystem__

#include <iostream>
//#include <GLUT/glut.h>

//#include "ofMain.h"
#include "Particle.h"
//#include "ofGLRenderer.h"

#define NUM_PARTICLES 3000
#define MAX_CONNECTIONS 50
#define DISTANCE_CONNECTIONS 10

class ParticleSystem : public ofBaseApp {
public:
    
    Particle particles[NUM_PARTICLES];
    
    ParticleSystem();
    void update();
    void draw();
    
private:
    void connectWithClosest(Particle::Posi origin);
};

#endif /* defined(__SoundBall__ParticleSystem__) */
