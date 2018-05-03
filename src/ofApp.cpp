#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(34);
    ofSetFrameRate(60);
    
    string filepath = ofSystemTextBoxDialog("Input MP3 audio filepath", "");
    
    player.load(filepath);
    player.play();
    
    sampleRate = player.getSampleRate();
    bufferSize = 512;

    int channels = player.getNumChannels();
    
    audioAnalyzer.setup(sampleRate, bufferSize, channels);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (player.isPlaying() == false) {
        exit();
    }
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    soundBuffer = player.getCurrentSoundBuffer(bufferSize);
    
    audioAnalyzer.analyze(soundBuffer);
    
    //Get the values from the audio analyzer
    rms     = audioAnalyzer.getValue(RMS, 0, smoothing);
    power   = audioAnalyzer.getValue(POWER, 0, smoothing);
    pitchFreq = audioAnalyzer.getValue(PITCH_FREQ, 0, smoothing);
    pitchConf = audioAnalyzer.getValue(PITCH_CONFIDENCE, 0, smoothing);
    pitchSalience  = audioAnalyzer.getValue(PITCH_SALIENCE, 0, smoothing);
    centroid = audioAnalyzer.getValue(CENTROID, 0, smoothing);
    
    //Normalized values (between 0 and 1)
    pitchFreqNorm   = audioAnalyzer.getValue(PITCH_FREQ, 0, smoothing, TRUE);
    centroidNorm = audioAnalyzer.getValue(CENTROID, 0, smoothing, TRUE);
    dissonance = audioAnalyzer.getValue(DISSONANCE, 0, smoothing);
  
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofTranslate(350, 0);
    int max_width = 150;
    int half_max_width = max_width / 2;
    int one_third_max_width = max_width / 3;
    int xpos = 0;
    int deltax = 100;
    int ypos = 30;
    int deltay = 50;
    
    float value, valueNorm;
    
    //draw rms
    value = rms;
    ofSetColor(ofColor::cyan);
    ofDrawCircle(xpos, ofApp::kyposition, value * max_width);
    
    //draw power
    incrementXandY(xpos, deltax, ypos, deltay);
    value = power;
    ofSetColor(ofColor::paleVioletRed);
    ofDrawCircle(xpos, ofApp::kyposition, value * max_width);
    
    //draw pitch frequency
    incrementXandY(xpos, deltax, ypos, deltay);
    value = pitchFreq;
    valueNorm = pitchFreqNorm;
    ofSetColor(ofColor::purple);
    ofDrawCircle(xpos, valueNorm * ofApp::kheight, half_max_width);

    //draw pitch confidence
    incrementXandY(xpos, deltax, ypos, deltay);
    value = pitchConf;
    ofSetColor(ofColor::orange);
    ofDrawCircle(xpos, value * ofApp::kheight, half_max_width);
    
    //draw centroid
    //centroid corresponds to the "brightness" of the sound
    //tends to be the opposite image of rms/power
    incrementXandY(xpos, deltax, ypos, deltay);
    value = centroid;
    valueNorm = centroidNorm;
    ofSetColor(ofColor::blanchedAlmond);
    ofDrawCircle(xpos, ofApp::kyposition, valueNorm * max_width);

    //draw dissonance
    incrementXandY(xpos, deltax, ypos, deltay);
    value = dissonance;
    ofSetColor(ofColor::lime);
    ofDrawCircle(xpos, ypos, value * max_width);
    
    //draw pitch salience
    incrementXandY(xpos, deltax, ypos, deltay);
    value = pitchSalience;
    ofSetColor(ofColor::cornflowerBlue);
    ofDrawCircle(xpos, value * ofApp::kheight, one_third_max_width);
    
    //draw GUI and other text
    
    gui.draw();
    ofSetColor(ofColor::mistyRose);
    ofDrawBitmapString("Keys 1-9: Play other audio tracks", 0, 10);
    
}

//--------------------------------------------------------------
void ofApp::incrementXandY(int &x, int deltax, int &y, int deltay) {
    x += deltax;
    y += deltay;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    player.stop();
    switch (key) {
       
        case '1':
            player.load("smooth.mp3");
            break;
        case '2':
            player.load("hotelcalifornia.mp3");
            break;
        case '3':
            player.load("secrets.mp3");
            break;
        case '4':
            player.load("clairdelune.mp3");
            break;
        case '5':
            player.load("10sec.mp3");
            break;
        case '6':
            player.load("koreanmilksong.mp3");
            break;
        case '7':
            player.load("blackdress.mp3");
            break;
        case '8':
            player.load("losiento.mp3");
            break;
        case '9':
            player.load("smoothjazz.mp3");
            break;
            

        default:
            break;
    }
    player.play();
    
}
//--------------------------------------------------------------
void ofApp::exit(){
    audioAnalyzer.exit();
    player.stop();
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
