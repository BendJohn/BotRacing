# Development
#### 4/9/2019
Created Proposal and started testing out libraries. Messed around with the ofxGUI library in snake and tried to add other addons to a new openframeworks project.<br/>
##### To Do:<br/>
Will test out creating random graphs and using the basic graphics library.<br/>
Problems:
1. Confused on how to add external libraries to a new openframeworks project.<br/>
#### 4/11/2019
Figured out how to add addons. Testing out ofxGraph. Just trying to create a basic graph and save it using ofApp update().<br/>
##### To Do:<br/>
Will begin creating a map for the algorithms to run through.<br/>
Problems:
1. Compile errors, cannot project a graph using ofxGraph properly.<br/>
#### 4/16/2019
Resolved graph issue. Begining project! Creating a single mini-problem for the bots to go through. Following of-snake style..<br/>
##### To Do:<br/>
spruce up map to make it look nice<br/>
add myTest to github so I can commit stuff<br/>
Problems:
1. Cannot add my project to github.<br/>
#### 4/17/2019
Resolved git tracking issue. Creating a single mini-problem for the bots to go through. Following of-snake style..<br/>
##### To Do:<br/>
spruce up map to make it look nice<br/>
add myTest to github so I can commit stuff<br/>
Problems:
1. I'm an idiot.<br/>
#### 4/18/2019
Added a pretty background, obstacle and a random bot.<br/>
##### To Do:<br/>
create a helper class to give bot information about the obstacle.<br/>
Problems:
1. The obstacle isn't moving the way I want to. For now, this isn't a big issue.<br/>
#### 4/24/2019
Got random bot to move around the screen in random directions..<br/>
Created a helper class to give bot information about the obstacle, called game engine class. The class kills the bot when it hits the bottom.<br/>
##### ToDo <br/>
Problems:
1. The program still moves the bot after it "dies" -- waste of space..<br/>
2. Need to get started on another bot and hopefully finish visuals by next code review.
#### 4/25/2019
Created a conditional bot, that will try to move in places where it won't die.<br/>
##### ToDo <br/>
Problems:
1. The program still moves the bot after it "dies" -- waste of space.<br/>
2. The shouldDelete function is a little wack.
#### 4/28/2019
Created a conditional bot, that successfully finishes the course, probabily in the fastest possible time. Unfortunately doing that created a bug is the shouldDelete function (the one that determines whether the bot hit an obstacle.<br/>
##### ToDo <br/>
Problems:
1. The program still moves the bot after it "dies" -- waste of space.<br/>
2. Need to preprocess a genetic bot.<br/>
3. Need to fix the shouldDelete function.
#### 4/29/2019
Working on the simple genetic bot. The shouldDelete function isn't working so I'm going to try to fix that first.<br/>
Fixed the shouldDelete function. The error was assuming the point given was the top left corner, but if the size is negative, it would be the bottom left corner..<br/>
Created a lot of methods for the genetic bot: getFitness(), and its helpers. GetFitness calculates how good the bot's position is at a certain point. I also stop the bots movements 6 moves after it has gone through its previous generations moves.<br/>
##### ToDo <br/>
Problems:
1. The program still moves the bot after it "dies" -- waste of space.<br/>
2. Need to preprocess a genetic bot.<br/>
#### 4/30/2019
Created a population class that holds 100 simple genetic bots, which updates and sorts the bots. It also has a method that creates the next generation.<br/>
Abstracted drawSimpleGeneticBot to take in a reference to a simple genetic bot.<br/>
Created Genetic bot with population of size 10, and it fails to pass the obstacle.<br/>
Genetic bot of size 100 successfully passes the obstacle. It chooses 10 new moves each generation.<br/>
Added graph ofApp, it is horrible. It errors whenver my mouse hovers over it.<br/>
Graph is now multiplot graphing the fitness of the genetic bot, hopefully will graph the "fitness" of other bots as well. <br/>
##### ToDo <br/>
Problems:
1. The program still moves the bot after it "dies" -- waste of space.<br/>
2. Need to add title to the graph so it looks nicer :)<br/>
#### 5/i/2019
Found the genetic populations top speciman and tracked it by making it a different color. I knew the top speciman was the first one in the list of bots, because that is how I created the next generation.<br/>
I am wokrking on being able to skip generations to make it easier for the project presention.<br/>
##### ToDo <br/>
Problems:
1. The program still moves the bot after it "dies" -- waste of space.<br/>
2. Need to add title to the graph so it looks nicer :)<br/>
3. Usee 'N' to skip generations
