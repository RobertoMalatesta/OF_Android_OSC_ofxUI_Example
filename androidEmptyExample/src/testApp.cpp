#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	//static const int PORT = 11011;
	oscreceive.setup(1234);

	ofEnableSmoothing();
	ofBackground(0);


	gui = new ofxUICanvas(160, 10, 160, ofGetHeight());
	gui -> addWidgetDown(new ofxUILabel("PANEL 1: BASICS", OFX_UI_FONT_SMALL));
	gui -> addWidgetDown(new ofxUIRotarySlider(20*4, 0, 100, 50, "R2SLIDER"));
	gui -> addWidgetDown(new ofxUIRotarySlider(20*4, 0, 100, 50, "R3SLIDER"));

	ofBackground(233, 52, 27);
}

//--------------------------------------------------------------
void testApp::update(){

	// check for waiting messages
	while(oscreceive.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
	    oscreceive.getNextMessage(&m);
	    if (m.getAddress() == "/touch/touched"){
	    	touched = m.getArgAsInt32(0);
	    }
	    if (m.getAddress() == "/touch/point"){
	    	touchPointX = m.getArgAsInt32(0);
	    	touchPointY = m.getArgAsInt32(1);
	    }
	    if (m.getAddress() == "/touch/radius"){

	    }



	}//while



}

//--------------------------------------------------------------
void testApp::draw(){
	if (touched){
		ofCircle(5,5,10);
		ofCircle(touchPointX,touchPointY,30);
	}

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::touchDown(int x, int y, int id){
	touched = true;
	touchPointX = x;
	touchPointY = y;

}

//--------------------------------------------------------------
void testApp::touchMoved(int x, int y, int id){

}

//--------------------------------------------------------------
void testApp::touchUp(int x, int y, int id){
	touched = false;

}

//--------------------------------------------------------------
void testApp::touchDoubleTap(int x, int y, int id){

}

//--------------------------------------------------------------
void testApp::touchCancelled(int x, int y, int id){

}

//--------------------------------------------------------------
void testApp::swipe(ofxAndroidSwipeDir swipeDir, int id){

}

//--------------------------------------------------------------
void testApp::pause(){

}

//--------------------------------------------------------------
void testApp::stop(){

}

//--------------------------------------------------------------
void testApp::resume(){

}

//--------------------------------------------------------------
void testApp::reloadTextures(){

}

//--------------------------------------------------------------
bool testApp::backPressed(){
	return false;
}

//--------------------------------------------------------------
void testApp::okPressed(){

}

//--------------------------------------------------------------
void testApp::cancelPressed(){

}
