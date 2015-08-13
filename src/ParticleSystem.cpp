//
//  ParticleSystem.cpp
//  SoundBall
//
//  Created by blag on 11/08/15.
//
//

#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {
    
    for(int i = 0; i < NUM_PARTICLES; i++) {
        float theta = ofRandom(0,TWO_PI);
        float u = ofRandom(-1,1);
        particles[i] = Particle(theta,u);
    }
}

void ParticleSystem::update() {
    for(int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].update();
    }
}

void ParticleSystem::draw() {
    //ofSetColor(80,80,80);
    //glutSolidSphere(140, 64, 64);
    
    ofSetColor(255, 255, 255); //white
    for(int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].draw();
        connectWithClosest(particles[i].getPosition());
    }
//    for(int i = 0; i < NUM_PARTICLES; i++) {
//        for(int j = i+1; j < NUM_PARTICLES; j++) {
//            ofVec3f start = particles[i].position();
//            ofVec3f end = particles[j].position();
//            ofSetColor(255, 255, 255);
//            ofSetLineWidth(1);
//            ofLine(start, end);
//            //ofLine(start.x, start.y, start.z, end.x, end.y, end.z);
//        }
//    }
}

void ParticleSystem::connectWithClosest(Particle::Posi origin){
    int counter = 0, i = 0;
    while (counter < MAX_CONNECTIONS or i < NUM_PARTICLES) {
        if (((particles[i].getPosition().x <= origin.x+DISTANCE_CONNECTIONS) and (particles[i].getPosition().x >= origin.x-DISTANCE_CONNECTIONS)) and
            ((particles[i].getPosition().y <= origin.y+DISTANCE_CONNECTIONS) and (particles[i].getPosition().y >= origin.y-DISTANCE_CONNECTIONS)) and
            ((particles[i].getPosition().z <= origin.z+DISTANCE_CONNECTIONS) and (particles[i].getPosition().z >= origin.z-DISTANCE_CONNECTIONS))) {
            
            Particle::Posi end = particles[i].getPosition();
            ofSetColor(255, 255, 255);
            ofSetLineWidth(1);
            //ofLine(origin, end);
            ofLine(origin.x, origin.y, origin.z, end.x, end.y, end.z);
            ++counter;
        }
        ++i;
    }

}