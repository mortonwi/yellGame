# The Yelling Game
Will Morton's Oregon State University ENGR 103 Final Project

## Description

This is the Yelling Game where the goal is to test your yelling abilities. There are two modes: singleplayer and multiplayer. In singleplayer mode you test your ability to yell at the right levels to progress through each stage. In multiplayer you go head to head with another player and see who yells the loudest!

## Installation

This game requires an Adafruit Playground Express, a Micro-USB cable, and a working computer that can run the Arduino IDE. Links to these materials can be found at the bottom of the README. 

1. Make sure you have downloaded the Arduino IDE. 
2. Download the yellGame.ino file and open it inside of the Arduino IDE. 
3. Connect your Adafruit Circuit Playground Express to your computer via the micro-usb cable.
4. Within the Arduino IDE, install the Adafruit Circuit Playground library using the "Library Manager" icon on the left side of the IDE (It looks like books.)
5. Make sure that the Circuit Playground board is selected by checking near the top of the screen. 
6. Press the upload button and enjoy the game!

## How To Play

### Helpful Notes

For each of the modes, the Circuit Playground Express board should be held with the Micro-USB port at the top so that the text is readable.
To change between modes, flip the switch near the bottom of the Circuit Playground Express board. 

### Singleplayer

The singleplayer game mode is designed to test a players yelling ability (to an extent). 
This game mode starts out by flashing a green LED 4 times, this is the target noise level for the player to hit. 
These target noise levels range from the LED on the left of the Micro-USB port (quietest) to the LED on the right side of the Micro-USB port (loudest). 
After the green LED flashes, all of the LEDs will flash red, then yellow, and then finally green. This is a 'Ready Set Go' indicator. 
After the 'Ready Set Go' color pattern, the player has a few seconds to create enough noise to reach the target. Be careful to not go over the target!
If the player reaches the target without going over, the LEDs will all flash green and a nice sound will play. This indicates that the player succeeded. 
If the player doesn't reach the target or they exceed the target noise level, the LEDs will flash red and a bad sound will play. This indicates that the player failed. 
After either suceeding or failing, the game will restart and select a new target level for the player to reach.
After each round, the player can also change to mulitplayer by changing the switch direction. 

### Multiplayer

The multiplayer game mode pits two players against each other in a contest to see who is the loudest.
This game mode uses the two buttons on the Circuit Playground Express. One is labeled as A and the other is B.
To start, make sure the switch is in the 'Multiplayer' diraction. 
Each player should then pick a button that they will be (either A or B). 
Then the players will determine who will go first (Rock, Paper, Scissors is a good option to determine this). 
The player that is going first will press their button. This will start a 'Ready Set Go' color pattern. 
After the 'Ready Set Go' color pattern, the player has 4 seconds to make as much noise as possible. 
Their score will then be displayed in a very similar fashion to the singleplayer target indication. 
Then the second player will press their button and make as much noise as possible after the 'Read Set Go' sequence. 
After both players have had their 'turn' the game will determine who won by displaying red LEDs on the players side who lost and green LEDs on the players side who won. 
After the game end sequence, the multiplayer mode will restart. Players can also switch to the singleplayer mode at this time.

## Material Links

Arduino IDE: https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE.

Adafruit Circuit Playground Express: https://www.adafruit.com/product/3333.

Micro-USB cable: https://www.amazon.com/Charging-Transfer-Android-Trustable-MYFON/dp/B098DW7485/ref=sr_1_3?keywords=micro+usb+cable&qid=1685849370&sr=8-3.
