#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    point.reset();
    point.setPosition(ofPoint(ofGetWidth()/2,
                              ofGetHeight()/2));
    point.setCurve(LINEAR);
    gui.setup();
    gui.setPosition(0, 30);
    gui.add(size.setup("size",1,1,8));
    gui.add(btnClear.setup("clear"));
    gui.add(color.setup("color", ofColor(255,172,95),
                        ofColor(255,255,255),
                        ofColor(0,0,0)));
  
    fftSmooth = new float [8192];
      for (int i=0; i < 8192; i++) {
          fftSmooth[i] = 0;
      }
      reactive = 64;
    fbo.allocate(width, height);
    fbo.begin();
    ofClear(255);
    fbo.end();
    music.load("church.wav");
 //     music.load("last alliance.mp3");
    music.setVolume(0.8);
   music.setLoop(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    double dt = ofGetLastFrameTime();
    point.update(dt);
    if (point.hasFinishedAnimating() && !pointsQ.empty()) {
        point.animateTo(pointsQ.front());
        pointsQ.pop();
    }
    if(btnClear){
        fbo.begin();
        ofClear(255);
        fbo.end();
    }
    
    ofSoundUpdate();
    float * value = ofSoundGetSpectrum(reactive);
    for(int i=0; i < reactive; i++) {
        fftSmooth[i] *= 0.15f;
        if (fftSmooth[i] < value[i]) {
            fftSmooth[i] = value[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::black);
    ofDrawBitmapStringHighlight("RIPPLES", 10, 10);
     ofDrawBitmapStringHighlight("Play with color & sizes", 10, 25);
    //ofSetColor(color);
    fbo.draw(0,0);
       gui.draw();
    for(int i = 0; i < reactive; i++){
                ofNoFill();
             ofSetColor(color);
             ofSetLineWidth(size);
                ofDrawCircle(point.getCurrentPosition(), -(fftSmooth[i]*170));
            }
        
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  //  ofSetColor(color);
     fbo.begin();
  for(int i = 0; i < reactive; i++){
                 ofNoFill();
              ofSetColor(color);
              ofSetLineWidth(size);
                 ofDrawCircle(x, y, -(fftSmooth[i]*170));
             }
              fbo.end();
     // reference: https://www.youtube.com/watch?v=IiTsE7P-GDs&t=523s
   point.animateTo(ofPoint(x, y));
    music.setSpeed( 0.5f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*1.0f);
         music.setPan( ((float)(ofGetWidth() - x) / (float)ofGetWidth())*0.8f);
     if(button == 0) {
         music.play();}
   
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  
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
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
