ECE382_Lab8
===========
##Robot Maze
###Purpose
Combine lessons from previous labs and program the robot to navigate itself through a maze.
###Preliminary Design
My pseudocode for the lab is:
![alt text](https://github.com/mbergstedt/ECE382_Lab8/blob/master/Pseudocode.JPG?raw=true)
###Hardware Design
The hardware schematic is the same from lab 7:
![alt text](https://github.com/mbergstedt/ECE382_Lab8/blob/master/Hardware_Design.JPG?raw=true)
###Debugging
I used the movement code from lab 6 and the ir code from lab 7 to initialize those values.  I then designed a loop that would go straight if the robot was near the left wall, turn right if it ran into the front wall, or turn left if the left wall disappeared.  I had to play around with my front sensor sensitivity so that it would not run into the front wall, and delays so that the robot would turn far enough to keep going, but not too far.  Initially in my code, I tried to use different if statements, but that led to the robot performing one action and then checking another part, which led to uneven movement.  To fix it, I used one continuous if statement in the while loop.
###Testing Methodology/Results
I would load the code onto the robot and then I would put it in the lab to see how it acted.  If the robot did something that I did not like, I went back into the code and made adjustments to account for the differences between my expectations and the results.
###Documentation
None.
