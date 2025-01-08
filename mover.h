#ifndef MOVER_H
#define MOVER_H

#include "SDL2/SDL.h"
#include <iostream>
#include <vector>

/**
 * A class that only contains methods for
 * controlling the logic of the movement
 * of the square.
 */
class Mover
{
private:
    SDL_Rect& square;
    const std::vector<SDL_Rect>& obstacles;

public:
    Mover(SDL_Rect& square, const std::vector<SDL_Rect>& obstacles)
    : square(square), obstacles(obstacles) { }
    bool canMoveUp();
    bool canMoveDown();
    bool canMoveLeft();
    bool canMoveRight();
};

#endif