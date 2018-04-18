# Project Proposal

For my project, I would like to create a program that creates computer-generated graphics based on qualities (e.g. pitch, dissonance, etc.) of an audio file taken as input through a user interface. The graphics will be displayed as the audio is playing. Once the audio is finished, the graphics should stop and the window should close. I will use the libraries ofxGui and ofxAudioAnalyzer to create the image portion of the project. In order to play audio files, I will also have to use the ofxAudioDecoder addon. 

[Link to ofxAudioAnalyzer Github](https://github.com/leozimmerman/ofxAudioAnalyzer/blob/master/README.md#audio-file-player)

[Link to ofxAudioDecoder Github](https://github.com/kylemcdonald/ofxAudioDecoder)


I would like to implement this project as follows:

1) Figure out which qualities of the audio files I would like to base my image off of. 
2) Create an algorithm that takes the quantitative values of the audio file qualities and draws the corresponding picture (or displays the corresponding image). The algorithm will most likely consist of checking whether the weighted average of the quantitative values falls within a certain range, in which specific images will be displayed or drawn. Another option would be to have each quantitative attribute correspond to a different image, and the drawings of each image would depend on the value of each corresponding attribute. 
3) Implement the graphics based on the algorithm mentioned above. 
4) Implement the audio playing in the background as the picture is being drawn. Then make sure that the window closes as the audio ends. 
5) Implement the part of the GUI that allows the user to specify a filepath from which the audio file is taken as input. 