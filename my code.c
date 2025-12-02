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

