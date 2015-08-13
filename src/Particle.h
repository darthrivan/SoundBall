//
//  Particle.h
//  SoundBall
//
//  Created by blag on 11/08/15.
//
//

#ifndef __SoundBall__Particle__
#define __SoundBall__Particle__

#include <iostream>
#include "ofMain.h"

class Particle : public ofBaseApp{
public:
    
    float theta, u;
    float vTheta, vU;
    float x,y,z,radius;
    
    struct Posi{
        float x, y, z;
    };
    
    Particle();
    Particle(float _theta, float _u);
    Posi getPosition();
    void update();
    void draw();
};

#endif /* defined(__SoundBall__Particle__) */
