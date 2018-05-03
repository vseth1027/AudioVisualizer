# CS 126 FinalProject: Dancing Figures
This project provides a colorful visual representation of audio based on the audio's attributes. The program prompts the user for a filepath to an mp3 file, and then analyzes and displays corresponding graphics based on the audio's rms, power, pitch frequency, pitch confidence, centroid, dissonance, and pitch salience. If the user allows the audio to end, the GUI will close. While the music is playing, the user has the option to press any of the number keys 1-9 to see the visual representations of mp3 files included in the project. 

<h2>Getting Started</h2>
This project was created using the openframeworks library and the openframeworks addons ofxAudioAnalyzer, ofxAudioDecoder, and ofxGui. The project was initially based off of the example-allAlgorithms from the ofxAudioAnalyzer addon. 

<h3>Prerequisites</h3>
In order to run this project, one must download the openframeworks library as well as the addons ofxAudioAnalyzer and ofxAudioDecoder. Then, one must use the openframeworks project generator to generate the project by specifying the path to the project and selecting the three required addons. To run the project, one can open the project in Xcode (recommended) or run in the terminal using the makefile.  