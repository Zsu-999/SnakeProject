#include <ncurses.h>   // for drawing in terminal
#include <stdlib.h>   
#include <time.h>      // for seeding random numbers

#define WIDTH 40       // game board width
#define HEIGHT 20      // game board height

// simple struct to hold x,y positions
typedef struct {
    int x;
    int y;
} Point;

int main() {
    // setup ncurses screen
    initscr();              // start curses mode
    noecho();               // don't show keypresses
    curs_set(FALSE);        // hide cursor
    keypad(stdscr, TRUE);   // allow arrow keys
    timeout(100);           // snake speed (ms)

    // snake body array
    Point snake[100];
    int length = 3; // starting length
    snake[0].x = WIDTH/2;   // place head in middle
    snake[0].y = HEIGHT/2;

    // direction (dx,dy)
    int dx = 1; // start moving right
    int dy = 0;

    // food position
    Point food;
    srand(time(NULL));
    food.x = rand() % WIDTH;
    food.y = rand() % HEIGHT;

    // main game loop
    while (1) {
        clear(); // clear screen each frame

        // draw border (walls)
        for (int i=0; i<WIDTH; i++) {
            mvprintw(0,i,"#");           // top wall
            mvprintw(HEIGHT,i,"#");      // bottom wall
        }
        for (int i=0; i<=HEIGHT; i++) {
            mvprintw(i,0,"#");           // left wall
            mvprintw(i,WIDTH,"#");       // right wall
        }

        // draw food
        mvprintw(food.y, food.x, "*");

        // draw snake
        for (int i=0; i<length; i++) {
            mvprintw(snake[i].y, snake[i].x, "O");
        }

        // input handling
        int ch = getch(); // read key input
        if (ch == KEY_UP && dy==0) { dx=0; dy=-1; }
        else if (ch == KEY_DOWN && dy==0) { dx=0; dy=1; }
        else if (ch == KEY_LEFT && dx==0) { dx=-1; dy=0; }
        else if (ch == KEY_RIGHT && dx==0) { dx=1; dy=0; }

        // move snake (shift body forward)
        for (int i=length; i>0; i--) {
            snake[i] = snake[i-1];
        }
        snake[0].x += dx;
        snake[0].y += dy;

        // check if snake eats food
        if (snake[0].x == food.x && snake[0].y == food.y) {
            length++; // grow snake
            food.x = rand() % WIDTH;
            food.y = rand() % HEIGHT;
        }

        // check collision with wall (game over if hit)
        if (snake[0].x <= 0 || snake[0].x >= WIDTH ||
            snake[0].y <= 0 || snake[0].y >= HEIGHT) {
            break; // end game immediately
        }

        // check collision with itself
        for (int i=1; i<length; i++) {
            if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
                break; // end game immediately
            }
        }
    }

    endwin(); // end curses mode
    return 0;
}
