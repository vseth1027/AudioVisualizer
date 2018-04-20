I tested libraries ofxAudioAnalyzer with plan to use the All Algorithms Example as a starting point for the project. I must now figure out how I would like the images to be displayed according to the audio values. 

4/19/18
- Changed audio to play at the beginning of the app. 
- Modified draw to display the rms image as a circle.
- I was looking for a C++ equivalent of the Java Math.random() function and found the rand() function. I used that to have the rms image appear at random locations on the app. 
- Added images for the fields: rms, power, pitch frequency, and pitch confidence.
- I wanted to have the pitch frequency value's image be displayed on the y-axis according to its value, but I was having trouble with that because the values range from 0 to 30000. This worked with pitch confidence though, since that value is always between 0 and 1. '
    - SOLVED: The normalized values convert the actual values to fall within 0-1, so I should be using the normalized value instead. 
