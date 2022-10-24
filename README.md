# CPPND: Capstone Snake Game (I added new features for my capstone project)

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## Fitur that I added to Capstone Snake Game
Added new class called food as obstacles for food and poison. So the are two foods for snake,
one is yellow and one is red, the yellow is healthy food, the red is poison. Terminal will print message whether the 
snake eat poison or food with what are decreased/increased. Snake will die if eat poisons more than foods.
The scores, fps, number of poisons, number of foods ate by snake are shown on window title.

## Files and structure of class Food (Class that I added to this project)
I made two files for class Food, the base class (food.h) and food.cpp.
In the food.h file there are enum variable called TheColor, declare of attributes and methods of Food class i.e
constrctor, destructor, CheckTheColor(), SetColor(), Count(), GetCount(), ReduceCount(), foodBody, _theColor, and
_count. In the food.cpp there are definitons of the methods.

## Project's behave after I added the features
1. There are two kinds of food, the yellow one is food, the red one is poison.
2. There is snake.
3. Place the food and poison randomly.
4. If snake eat food, the length of its body will increase, the score will increase by one, the number of foods 
will increase by one, the number of foods will increase by one.
5. If snake eat poison, the length of its body will not increase (stay the same), the score will decrease by one,
the number of poisons will increase by one, and the number of foods will decrease by one.
6. If the number of poisons more than the number of foods, then the snake will die.
7. Snake will die if its eat their own body.

## Rubric points that I addresed:
1. Point number one in table "Loops, Functions, I/O", 
   Implemented in food.cpp (line 4 - 37), food.h (line 17 - 23), game.h (line 20 - 21), the functions/method called in game.cpp (line 81, 97 - 103, 116 - 127, 135, 145 - 148).
2. Point number one in table "Object Oriented Programming",
   Implemented in food.h (all lines) and food.cpp(all lines).
3. Point number two in table "Object Oriented Programming",
   Implemented in food.h (line 15 - 34).
4. Point number 5 in table "Object Oriented Programming",
   Implemented in food.h (line 17 - 21, line 27 - 30), food.cpp (all lines), game.h (line 20 - 21), the functions/methods called in game.cpp (line 81, 97 - 103, 116 - 127, 135, 145 - 148).
5. Point number 8 in the table "Object Oriented Programming",
   Impemented in food.h(line 9 - 11, 14, 23), food.cpp (line 14 - 16), the funtion called at game.cpp (line 100 & 119)


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
