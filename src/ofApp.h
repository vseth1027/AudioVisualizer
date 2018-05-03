#pragma once

#include "ofMain.h"
#include "ofxAudioAnalyzer.h"
#include "ofSoundPlayerExtended.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();
    
        void incrementXandY(int &x, int deltax, int &y, int deltay);

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
    
        ofxAudioAnalyzer audioAnalyzer;
        ofSoundPlayerExtended player;
    
        int sampleRate;
        int bufferSize;
    
        const static int kwidth = 1024;
        const static int kheight = 768;
        const static int kyposition = 400;
    
        ofSoundBuffer soundBuffer;
    
        float rms;
        float power;
        float pitchFreq;
        float pitchFreqNorm;
        float pitchConf;
        float pitchSalience;
        float hfc;
        float hfcNorm;
        float specComp;
        float specCompNorm;
        float centroid;
        float centroidNorm;
        float inharmonicity;
        float dissonance;
        float rollOff;
        float rollOffNorm;
        float oddToEven;
        float oddToEvenNorm;
        float strongPeak;
        float strongPeakNorm;
        float strongDecay;
        float strongDecayNorm;
    
    
    
    
    
        vector<float> spectrum;
        vector<float> melBands;
        vector<float> mfcc;
        vector<float> hpcp;
    
        vector<float> tristimulus;
    
        bool isOnset;
    
        ofxPanel gui;
        ofxFloatSlider smoothing;
    
    
    
};
