#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //*********************************
    //AUDIO
    //*********************************
    // 0 output channels,
	// 2 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	
	//soundStream.listDevices();
	
    //if you want to set a different device id
	soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio
    //devices, including  input-only and output-only devices.
	
    int BUFFER_SIZE = 512;

    left.assign(BUFFER_SIZE, 0.0);
	right.assign(BUFFER_SIZE, 0.0);
	volHistory.assign(400, 0.0);
	
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
    
	soundStream.setup(this, 0, 2, 44100, BUFFER_SIZE, 4);
    
    //*********************************
    //END OF AUDIO
    //*********************************
    
    //*********************************
    //SOUND BALL
    //*********************************
    
    ofSetVerticalSync(true);
    ofSetFrameRate(50);
    ofEnableAlphaBlending();
    ofBackground(0,0,0);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    
    sys.init();
    //*********************************
    //END OF SOUND BALL
    //*********************************
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //*********************************
    //AUDIO
    //*********************************
    
    // update the sound playing system:
	//ofSoundUpdate();

    //lets scale the vol up to a 1.0-4.5 range
	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 1.0, 4.5, true);
    
	//lets record the volume into an array
	volHistory.push_back( scaledVol );
	
	//if we are bigger the the size we want to record - lets drop the oldest value
	if( volHistory.size() >= 400 ){
		volHistory.erase(volHistory.begin(), volHistory.begin()+1);
	}
    
    //*********************************
    //END OF AUDIO
    //*********************************
    
    //*********************************
    //SOUND BALL
    //*********************************
    
    sys.modRad(scaledVol); //Modify particle system's radius
    //sys.modPartRad(1); //Modify some particles size depending on the HIGHs
        
    //*********************************
    //END OF SOUND BALL
    //*********************************
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(0), ofColor(0, 180, 200));
    //*********************************
    //SOUND BALL
    //*********************************
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
    sys.draw();
    //*********************************
    //END OF SOUND BALL
    //*********************************
    
    
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
	//*********************************
    //AUDIO
    //*********************************
	float curVol = 0.0;
	
	// samples are "interleaved"
	int numCounted = 0;
    
	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		right[i]	= input[i*2+1]*0.5;
        
		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted+=2;
	}
	
	//this is how we get the mean of rms :)
	curVol /= (float)numCounted;
	
	// this is how we get the root of rms :)
	curVol = sqrt( curVol );
	
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
    
    //*********************************
    //END OF AUDIO
    //*********************************
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
