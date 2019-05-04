# Bot Racing
<a href="http://www.youtube.com/watch?feature=player_embedded&v=Yo2SepcNyw4" target="_blank"><img src="http://img.youtube.com/vi/Yo2SepcNyw4/0.jpg" alt="AI learns to play World's Hardest Game" width="480" height="360" border="10" /></a>
<br />The above video and a fellow student named _Brian Furman_ are the inspiration for this project.
## Mission

...The mission for my project is to compare different types of AI algorithms, and see which ones are faster at solving a certain type of problem. From the minute background I have gained in CS 126 and CS 361, I believe that I have enough starting materials to discover more types of AI algorithms and being able to implement them into my design. At the end, the time it took for each algorithm to solve the problem will be displayed. The types of problems will vary to see which problems are more suited to be solved by a certain AI. It is like the visual of many different sorts that work fast on a particular type of list.

...In my graphics I will show the problem and the show the types of algorithms trying to reach the end goal. The end goal will be determined by a boolean, either a success, or a failure.

### Here are some of the types of problems:
| Problems      | Description                                                                                   |
| ------------- |:---------------------------------------------------------------------------------------------:|
| Maze (WHG)    | Like the Youtube video I showed above, the Maze will have a start and an end, with walls      |
| Move Accross  | AI will simply move across the page, the most basic version                                   |
| Minigame      | This is the most complex of all the problems, and there will be a point system                |

### Here are some of the types of AIs:
| AI BOTS          | Description                                                                                                |
| -----------------|:----------------------------------------------------------------------------------------------------------:|
| Genetic          | This evolutionary AI will randomize in gen 1 and then pass on the most successful AI to the next round     |
| Random           | AI will choose randomly from a list of possible moves                                                      |
| Human Conditional| Basically will be a whole bunch of if-statements                                                           |
| Monte Carlo      | A bot that calculates every possible move and chooses the best one                                         |

## Libraries
Most of the libraries I will use will be to create the graphics of the problem games. The libraries I will use are as follows:
1. *ofSoundPlayer*: An openframeworks library that produces sound that will enhance the games in the problems. Like a victory noise.
2. *ofxGui*: Since the minigames will be like the snake game, it will need this library. It will also let the user compare its choices to an AIs
3. *ofxChart*: To graph the differences in the AI bots, and to compare them against one another.

## Minimum Viable Product
The minimum viable product is to create an application with 3 AI bots for 1 minigame and chart the differences in time of the three minibots.
The mimimum viable graphics would be two pages, one with a single minigame and another with the results that automatically pop up after all the AI bots succeed.
