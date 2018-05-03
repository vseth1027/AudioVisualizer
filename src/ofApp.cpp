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
    
    //-:Get buffer from sound player:
    soundBuffer = player.getCurrentSoundBuffer(bufferSize);
    
    //-:ANALYZE SOUNDBUFFER:
    audioAnalyzer.analyze(soundBuffer);
    
    //-:get Values:
    rms     = audioAnalyzer.getValue(RMS, 0, smoothing);
    power   = audioAnalyzer.getValue(POWER, 0, smoothing);
    pitchFreq = audioAnalyzer.getValue(PITCH_FREQ, 0, smoothing);
    pitchConf = audioAnalyzer.getValue(PITCH_CONFIDENCE, 0, smoothing);
    pitchSalience  = audioAnalyzer.getValue(PITCH_SALIENCE, 0, smoothing);
    inharmonicity   = audioAnalyzer.getValue(INHARMONICITY, 0, smoothing);
    hfc = audioAnalyzer.getValue(HFC, 0, smoothing);
    specComp = audioAnalyzer.getValue(SPECTRAL_COMPLEXITY, 0, smoothing);
    centroid = audioAnalyzer.getValue(CENTROID, 0, smoothing);
    rollOff = audioAnalyzer.getValue(ROLL_OFF, 0, smoothing);
    oddToEven = audioAnalyzer.getValue(ODD_TO_EVEN, 0, smoothing);
    strongPeak = audioAnalyzer.getValue(STRONG_PEAK, 0, smoothing);
    strongDecay = audioAnalyzer.getValue(STRONG_DECAY, 0, smoothing);
    
    
    //Normalized values for graphic meters:
    pitchFreqNorm   = audioAnalyzer.getValue(PITCH_FREQ, 0, smoothing, TRUE);
    hfcNorm     = audioAnalyzer.getValue(HFC, 0, smoothing, TRUE);
    specCompNorm = audioAnalyzer.getValue(SPECTRAL_COMPLEXITY, 0, smoothing, TRUE);
    centroidNorm = audioAnalyzer.getValue(CENTROID, 0, smoothing, TRUE);
    rollOffNorm  = audioAnalyzer.getValue(ROLL_OFF, 0, smoothing, TRUE);
    oddToEvenNorm   = audioAnalyzer.getValue(ODD_TO_EVEN, 0, smoothing, TRUE);
    strongPeakNorm  = audioAnalyzer.getValue(STRONG_PEAK, 0, smoothing, TRUE);
    strongDecayNorm = audioAnalyzer.getValue(STRONG_DECAY, 0, smoothing, TRUE);
    
    dissonance = audioAnalyzer.getValue(DISSONANCE, 0, smoothing);
    
    spectrum = audioAnalyzer.getValues(SPECTRUM, 0, smoothing);
    melBands = audioAnalyzer.getValues(MEL_BANDS, 0, smoothing);
    mfcc = audioAnalyzer.getValues(MFCC, 0, smoothing);
    hpcp = audioAnalyzer.getValues(HPCP, 0, smoothing);
    
    tristimulus = audioAnalyzer.getValues(TRISTIMULUS, 0, smoothing);
    
    isOnset = audioAnalyzer.getOnsetValue(0);
  
   
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
    
    ofSetColor(255);
    value = rms;
    ofSetColor(ofColor::cyan);
    ofDrawCircle(xpos, ofApp::kyposition, value * max_width);
    
    incrementXandY(xpos, deltax, ypos, deltay);
    ofSetColor(255);
    value = power;
    ofSetColor(ofColor::paleVioletRed);
    ofDrawCircle(xpos, ofApp::kyposition, value * max_width);
    
    
    incrementXandY(xpos, deltax, ypos, deltay);
    ofSetColor(255);
    value = pitchFreq;
    valueNorm = pitchFreqNorm;
    ofSetColor(ofColor::purple);
    ofDrawCircle(xpos, valueNorm * ofApp::kheight, half_max_width);

    incrementXandY(xpos, deltax, ypos, deltay);
    ofSetColor(255);
    value = pitchConf;
    ofSetColor(ofColor::orange);
    ofDrawCircle(xpos, value * ofApp::kheight, half_max_width);
    
    incrementXandY(xpos, deltax, ypos, deltay);
    ofSetColor(255);
    value = centroid;
    valueNorm = centroidNorm;
    ofSetColor(ofColor::blanchedAlmond);
    ofDrawCircle(xpos, ofApp::kyposition, valueNorm * max_width);
    //centroid corresponds to the "brightness" of the sound
    //tends to be the opposite image of rms/power
    

    incrementXandY(xpos, deltax, ypos, deltay);
    ofSetColor(255);
    value = dissonance;
    ofSetColor(ofColor::lime);
    ofDrawCircle(xpos, ypos, value * max_width);
    
  
    incrementXandY(xpos, deltax, ypos, deltay);
    ofSetColor(255);
    value = pitchSalience;
    ofSetColor(ofColor::cornflowerBlue);
    ofDrawCircle(xpos, value * ofApp::kheight, one_third_max_width);
    
    //-Gui & info:
    
    gui.draw();
    ofSetColor(255);
    ofSetColor(ofColor::hotPink);
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
