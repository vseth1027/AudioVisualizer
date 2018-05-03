4/16/2018
- I tested libraries ofxAudioAnalyzer with plan to use the All Algorithms Example as a starting point for the project. I must now figure out how I would like the images to be displayed according to the audio values. 

4/19/2018
- Changed audio to play at the beginning of the app. 
- Modified draw to display the rms image as a circle.
- I was looking for a C++ equivalent of the Java Math.random() function and found the rand() function. I used that to have the rms image appear at random locations on the app. 
- Added images for the fields: rms, power, pitch frequency, and pitch confidence.
- I wanted to have the pitch frequency value's image be displayed on the y-axis according to its value, but I was having trouble with that because the values range from 0 to 30000. This worked with pitch confidence though, since that value is always between 0 and 1. '
    - SOLVED: The normalized values convert the actual values to fall within 0-1, so I should be using the normalized value instead. 

4/22/2018
- Added image representation for the centroid. It is interesting to note that the circle image representation for the centroid attribute is almost exactly opposite of those for power and rms. 
- Started researching ways to allow the user to specify files for the graphics. 
    - Problem: How does one calcluate the sample rate, buffer size, and number of channels for an audio file (WAV or mp3)?
        - I can use a getter method for the sample rate and number of channels. 
        - Buffer size problem is preventing the program from being able to take any input file. 
    - SOLVED: The 512 buffer size is fine for mp3 files, but not wav files. Prompt the user for an mp3 file instead. Keep looking for a way to find the buffer size for a wav file. 

4/24/2018
- Edited update() so that the window will close once the audio finishes playing. 
- PROBLEM: Sometimes the application is run from the terminal and the application starts buts fails. When this happens, the incorrect app logo is displayed in the dock (on mac) and in the program window itself. Why is this happening, and how can this be fixed?

5/1/2018
- Added image representation for pitch salience.
- Deleted .wav files and added the option to play some extra tracks when the number keys 1-9 are pressed. (modifed keyPressed() method) 

5/2/2018
- Wrote README.md for project. 
- PROBLEM: For some reason, the in text links do not show up correctly on github. I used the same syntax for the addon links in my proposal, but they are not working in the README. For now I have removed them. 
- Added method incrementXandY() in order to make code more D.R.Y.
- Added constants to eliminate magic numbers.
