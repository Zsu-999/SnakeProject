
// draw border (walls)
for (int i = 0; i < WIDTH; i++) {
    mvprintw(0, i, "#");           // Draw top wall row at y=0
    mvprintw(HEIGHT, i, "#");      // Draw bottom wall row at y=HEIGHT
}
for (int i = 0; i <= HEIGHT; i++) {
    mvprintw(i, 0, "#");           // Draw left wall column at x=0
    mvprintw(i, WIDTH, "#");       // Draw right wall column at x=WIDTH
}

// draw food
mvprintw(food.y, food.x, "*");     // Display food at its (x,y) position using '*'

// check if snake eats food
if (snake[0].x == food.x && snake[0].y == food.y) {  // If snake head overlaps food
    length++;                                        // Increase snake length by 1
    food.x = rand() % (WIDTH - 2);                  // Generate new food x inside walls
    food.y = rand() % (HEIGHT - 2);                 // Generate new food y inside walls
}

// check collision with wall (game over if hit)
if (snake[0].x <= 0 || snake[0].x >= WIDTH ||       // If head hits left/right wall
    snake[0].y <= 0 || snake[0].y >= HEIGHT) {      // Or hits top/bottom wall
    break;                                           // End game loop immediately
}

// check collision with itself
for (int i = 1; i < length; i++) {                  // Loop through snake body segments
    if (snake[0].x == snake[i].x &&                 // If head position matches any body segment
        snake[0].y == snake[i].y) {
        break;                                       // End game loop immediately
    }
}

