#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxAnimatable.h"
#include "ofxAnimatableOfPoint.h"
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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    
    ofSoundPlayer music;
    ofxPanel gui;
    ofxColorSlider color;
    ofxIntSlider size;
    ofxAnimatableOfPoint point;
     ofxButton btnClear;
    queue<ofPoint> pointsQ;
    ofFbo fbo;
       int width = 1024;
       int height = 786;
    float * fftSmooth;
       int reactive;
}; 

