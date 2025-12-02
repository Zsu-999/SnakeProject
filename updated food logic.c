// draw food
mvprintw(food.y, food.x, "*");

// check if snake eats food
if (snake[0].x == food.x && snake[0].y == food.y) {
    length++; // grow snake
    food.x = rand() % (WIDTH -2)) + 1;
    food.y = rand() % (HEIGHT -2)) + 1;
}