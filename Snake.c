#include <ncurses.h>  //Drawing in the terminal
#include <stdlib.h>   
#include <time.h>     //Seeding random numbers 

#define WIDTH 40
#define HEIGHT 20

// simple structure to hold x,y positions 
typedef struct {
int x;
int y;
} Point;
//Starting set up 
int main () {
initscr();   //Start curses mode
noecho();    // hides keypresses
curs_set(FALSE); //hide cursor
keypad(stdscr, TRUE); //allow arrow keys 
timeout(100);         //snakes speed (ms)
//snakes body 
Point snake[100];
int length = 3;   //Starting length 
snake[0].x= WIDTH/2 //places the snakes head in the middle 
snake[0].y= HEIGHT/2

//Directions (dx,dy)
int dx= 1; //starting direction is right
int dy= 0;


//Key inputs 
int ch= getch();
if(ch==KEY_UP && dy==0) { dx=0; dy=-1; }
else if (ch == KEY_DOWN && dy==0) { dx=0; dy=1;}
else if (ch == KEY_LEFT && dx==0) { dx=-1; dy=0;}
else if (ch == KEY_RIGHT && dx==0) { dx=1; dy=0;}

//Move snakes (shift body forward)
for (int i=length; i>0; i--) {
    snake[i] = snake [i-1];

}
snake[0].x += dx;
snake[0].y += dy;




}
