#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    videoIn.setDeviceID(0);
    vidGrabber.initGrabber(1920,1080);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    if(STATE_RECORDING) {
        if(videoIn.isFrameNew()) {
            videoSaver.addFrame(&videoIn);
        }
    } else if(STATE_REVIEWING) {
        
        
    }

}


void ofApp::acceptVideo() {
    if(state == STATE_WAITING_FOR_USER_FEEDBACK) {
    
    }
}

void ofApp::rejectVideo() {
    if(state == STATE_WAITING_FOR_USER_FEEDBACK) {
        // discard recorded data
        state = STATE_WAITING_FOR_NEW_USER;
    }
}

void ofApp::newUser() {
    if(state == STATE_WAITING_FOR_NEW_USER) {
        state = STATE_INTRODUCTION;
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(state == STATE_WAITING_FOR_USER_FEEDBACK) {
        
        if(key == "a") {
            // emulated button press: accept
            // save file
            acceptVideo();
            
        } else if(key=="r") {
            // emulated button press: reject
            rejectVideo();
            
        }
        
    }
    
    if(state == STATE_WAITING_FOR_NEW_USER) {
        if(key == "a") {
            newUser();
        }
    }
    
    
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
