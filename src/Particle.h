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
    
private:
    float theta, u;
    float vTheta, vU;
    float x,y,z;
    float partSizeModi; //Modifier for particles size (particle radius)
    bool isUpdated;
    vector<Particle*> near;
    
public:
    
    Particle();
    Particle(float _theta, float _u, float radius);
    float getPositionX();
    float getPositionY();
    float getPositionZ();
    void copyParticle(Particle p);
    void copyParticleConnections(Particle p);
    void addNearParticle(Particle* pa);
    int getNumberNearParticles();
    bool getIsUpdated();
    void setPartSizeModi(float p);
    void updateRadius(float radius, float modifier); //This updates the WHOLE system radius
    void update(float radius);
    void draw();
};

#endif /* defined(__SoundBall__Particle__) */
