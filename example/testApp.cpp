#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(30);

	ofBackground(0,0,0);
	TTF.loadFont("mono.ttf", 7);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(240, 240, 240);

	message = "ofxMSATimer.getAppTime(): " + ofToString(ofMSATimer.getAppTime()) + " sec";
	TTF.drawString(message, 100, 120);

	message = "ofxMSATimer.getMachAbsoluteTime(): " + ofToString(ofMSATimer.getMachAbsoluteTime()) + " ns";
	TTF.drawString(message, 100, 140);

	double elapsedTimeSec = ofMSATimer.getElapsedTime();
	message = "ofxMSATimer.getElapsedTime(): " + ofToString(elapsedTimeSec*1000) + " ms"; //To millis
	TTF.drawString(message, 100, 160);

	message = "ofxMSATimer.getAppTimeMillis(): " + ofToString(ofMSATimer.getAppTimeMillis()) + " ms";
	TTF.drawString(message, 100, 180);

	message = "ofxMSATimer.getTimeSinceLastCall(): " + ofToString(ofMSATimer.getTimeSinceLastCall()) + " sec";
	TTF.drawString(message, 100, 200);

	message = "FPS: " + ofToString(1/elapsedTimeSec);
	TTF.drawString(message, 100, 100);

	ofMSATimer.setStartTime();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}