# SnakeProject
Shaun Hills and Zachary Geisler group project 

Gameplay Overview

This is a classic Snake game implemented in C using the ncurses library for terminal graphics.
How It Works


Game Board:
The board is a rectangular grid of 40 columns (width) and 20 rows (height), surrounded by walls represented by #.


Snake:

Starts with a length of 3 segments, positioned in the center of the board.
The snake moves continuously in the current direction (initially right).
You control the snake using arrow keys:

Up: ↑
Down: ↓
Left: ←
Right: →


The snake cannot reverse direction directly (e.g., if moving right, you cannot immediately go left).



Food:

Represented by * on the board.
Appears at a random position inside the walls.
When the snake’s head reaches the food:

The snake grows by one segment.
A new food item spawns at a random location.





Game Speed:
The snake moves every 100 ms, controlled by timeout(100).


Game Over Conditions:

Snake hits a wall.
Snake collides with itself.



Display:

Snake segments are drawn as O.
Food is drawn as *.
Walls are drawn as #.



End of Game:
When the snake collides with a wall or itself, the game loop ends and the program exits.
