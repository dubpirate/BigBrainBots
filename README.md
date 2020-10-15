# BigBrainBots 🤖

Built by William Torkington, Hugh Marshall, and Zach Konings.

## Game Architecture 👷

The levels were intended to be structured in the following order:

 - Prologue (the Tutorial)
 - World One: Zeuthian Station (2 Levels)
 - World Two: Susanova Canyon (2 Levels)
 - World Three: Raihujin Fortress (2 Levels)
 - World Four: Setlith Chambers (2 Levels)
 
Each level represents a puzzle or set of puzzles the player must solve using the special abilities of the four bots. 

As can be seen in [the Levels directory,](https://github.com/dubpirate/BigBrainBots/tree/master/Content/Levels), three of the four worlds have level models made, and only the [Prologue](https://github.com/dubpirate/BigBrainBots/tree/master/Content/Levels/Prologue_Level) and [Zeuthian Station Level One](https://github.com/dubpirate/BigBrainBots/tree/master/Content/Levels/Zeuthian_Station/Level_01) were fully finished and playable. 

## Installation and Setup 🐪

This game requires Unreal Engine 4.25.3 or later, which can be downloaded from the (Unreal Engine Website)[https://www.unrealengine.com/en-US/download]. 

To install, first clone or download this repository, using

`git clone https://github.com/dubpirate/BigBrainBots.git` 

or by clicking the green __↓ Code__ button on the top of the screen, and selecting __Download Zip__. 

Then, navigate to the directory inside titled `BigBrainBots`. Inside, there should be the following files:

 - __BigBrainBots.uproject__
 - Config
 - README.md
 - Source
 - Content
 
Double clicking __BigBrainBots.uproject__ should open the game in Unreal Engine.

It will open on a the default "TopDownExampleMap" we were using to sandbox ideas, as seen below.

![Image of Sandbox](https://drive.google.com/file/d/1lJJZSceiUi7cw2xjBAsCIS1eeg2hKDoJ/view?usp=sharing)

Or you can navigate to Levels, as seen below, and double click on the Prologue_Level/Level_Prologue.umap or /Zeuthian_Station/Level_01/Level_Layout_ZS1.umap to see a functioning level.

![Navigation to Prologue Level](https://drive.google.com/file/d/1GOMc3uvQQiLF8h-9eM0h0pzKLVm0DBVY/view?usp=sharing)

When you've chosen a level, hit the play button on the top right hand corner.

## Controls 🍊

### Movement ✌️

__W, A, S, D__ control the movement of each bot, and __the mouse__ controls the camera.

Use __Tab__ or __1, 2, 3, 4__ to switch between bots.

### Special Abilities 👼

Each bot can interact with the environment in different ways. 

StandardBot uses __E__ to activate levers.

FlyBot uses __E__ to press buttons in high up places.

GasBot uses __E__ to activate his aura, that stops robots taking damage from... gas. Yeah, we know.

HeavyBot can sit on pressureplates, because he's heavy.
