#include "mover.h"

/**
 * Checks if the square can move up
 */
bool Mover::canMoveUp()
{
    int goal = obstacles.size(); // Current obstacles
    int counter = 0;

    for (const SDL_Rect& obstacle : obstacles)
    {
        if (square.y > obstacle.y + obstacle.h
            || square.y <= obstacle.y - square.h
            || square.x <= obstacle.x - square.w
            || square.x >= obstacle.x + obstacle.w)
            counter++;
    }

    // All of the obstacles allow the square to move
    if (counter == goal)
        return true;

    return false;
}

/**
 * Checks if the square can move down
 */
bool Mover::canMoveDown()
{
    int goal = obstacles.size(); // Current obstacles
    int counter = 0;

    for (const SDL_Rect& obstacle : obstacles)
    {
        if (square.y < obstacle.y - square.h
            || square.y >= obstacle.y + obstacle.h
            || square.x <= obstacle.x - square.w
            || square.x >= obstacle.x + obstacle.w)
            counter++;
    }

    // All of the obstacles allow the square to move
    if (counter == goal)
        return true;

    return false;
}

/**
 * Checks if the square can move to the left
 */
bool Mover::canMoveLeft()
{
    int goal = obstacles.size(); // Current obstacles
    int counter = 0;

    for (const SDL_Rect& obstacle : obstacles)
    {
        if (square.x > obstacle.x + obstacle.w
            || square.x <= obstacle.x - square.w
            || square.y >= obstacle.y + obstacle.h
            || square.y <= obstacle.y - square.h)
            counter++;
    }

    // All of the obstacles allow the square to move
    if (counter == goal)
        return true;

    return false;
}

/**
 * Checks if the square can move to the right
 */
bool Mover::canMoveRight()
{
    int goal = obstacles.size(); // Current obstacles
    int counter = 0;

    for (const SDL_Rect& obstacle : obstacles)
    {
        if (square.x < obstacle.x - square.w
            || square.x >= obstacle.x + obstacle.w
            || square.y >= obstacle.y + obstacle.h
            || square.y <= obstacle.y - square.h)
            counter++;
    }

    // All of the obstacles allow the square to move
    if (counter == goal)
        return true;

    return false;
}