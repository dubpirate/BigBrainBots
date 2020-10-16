# BigBrainBots 🤖

Designers: Billy Chang and Marcus Carey
Programmers: William Torkington, Hugh Marshall, and Zach Konings.

BigBrainBots is a single-player puzzle adventure game, with a focus on environmental interaction. Four brave robots must use all of the tools at their disposal to escape from servitude - or be turned into scrap.

Some of our game's key features include:

- Four independent robots to play as at once.
- An extensible, versatile interaction scheme that ties the environment together.
- A set of levels with unique, distinct designs.
- Many dangerous and deadly environmental hazards.

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

Use __Tab__, __Shift__ or __1, 2, 3, 4__ to switch between bots.

### Special Abilities 👼

Each bot can interact with the environment in different ways. 

StandardBot uses __E__ to activate levers.

FlyBot uses __E__ to press buttons in high up places.

GasBot uses __E__ to activate his aura, that stops robots taking damage from... gas. Yeah, we know.

HeavyBot can sit on pressureplates, because he's heavy.

## Puzzle Pieces 🦾

The Prologue will give you a good sense of the implemented features of BigBrainBots.

The first few rooms  in the Prologue demonstrate the three kinds of switches, the pressureplate, and the buttons. The kinds of switches are aptly titled the Hold Switch because it doesn't change until you move away, the Timed Switch that deactivates after a delay, and the Flip Switch that stays in whatever state you set it in. These are all separated by triggerable doors that react to different inputs and interactions.


Some other features that are not implemented in the prologue, for instance:

 - BatteryBot is a mini puzzle that was intended to be in the Susanova Canyon. An example BatteryBot can be found in the SandBox. You control a BatteryBot by stepping on a series of Directional Pressureplates. If you navigate to the charging station (a blue box) then press the pressureplate next to the charging station, a light will appear, indicating that the BatteryBot has been charged. This allows it to activate other interactables, and thereby complete puzzles.
 
- FlyBot Elevators allow FlyBot to maintain a hover height relative to the elevator it's standing on, a fix harder than expected.
