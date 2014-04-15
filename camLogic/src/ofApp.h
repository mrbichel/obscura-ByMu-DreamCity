#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"
#include "ofxVideoSaver.h"

enum {STATE_RECORDING, STATE_WAITING_FOR_NEW_USER, STATE_INTRODUCTION, STATE_REVIEWING, STATE_WAITING_FOR_USER_FEEDBACK};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    void acceptVideo();
    void rejectVideo();
    
    void newUser();
    
    ofSerial arduino;
    
    int state;
    
    ofVideoGrabber videoIn;
    
    ofxSyphonServer syphonOut;
    
    int recordLength;
    
    bool recording;
    
    ofVideoPlayer videoPlayback;
    
    ofxVideoSaver videoSaver;
    
    int long introductionTime = 1000;
    int long introductionStart = 0;
    
};
