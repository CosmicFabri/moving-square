#include "SDL2/SDL.h"
#include "mover.h"
#include <iostream>
#include <vector>

// Our window dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Our square dimensions
#define SQUARE_WIDTH 40
#define SQUARE_HEIGHT 40

// Function prototypes
std::vector<SDL_Rect> createObstacles();
void drawObstacles(SDL_Renderer* renderer);

// Vector of obstacles
std::vector<SDL_Rect> obstacles;

int main(int argc, char *argv[])
{
    // Unused argc, argv;
    // muting alerts
    (void)argc;
    (void)argv;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL could not be initialized!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl;

        return 0;
    }

    // Create window
    SDL_Window *window = SDL_CreateWindow("Move the square!",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH,
                                          SCREEN_HEIGHT,
                                          SDL_RENDERER_ACCELERATED);

    if (!window)
    {
        std::cout << "Window could not be created!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        // Create renderer
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (!renderer)
        {
            std::cout << "Renderer could not be created!" << std::endl
                      << "SDL_Error: " << SDL_GetError() << std::endl;
        }
        else
        {
            // Declare rect of square
            SDL_Rect squareRect;

            // Square dimensions
            squareRect.w = SQUARE_WIDTH;
            squareRect.h = SQUARE_HEIGHT;

            // Square position: in the middle of the screen
            squareRect.x = (SCREEN_WIDTH - SQUARE_WIDTH) / 2;
            squareRect.y = (SCREEN_HEIGHT - SQUARE_HEIGHT) / 2;

            // Creating the obstacles
            obstacles = createObstacles();

            // Creating the Mover object
            Mover mover(squareRect, obstacles);

            // Event loop exit flag
            bool quit = false;

            // Event loop
            while (!quit)
            {
                SDL_Event e;

                // Wait indefinitely for the next available event
                SDL_WaitEvent(&e);

                // User requests quit
                if (e.type == SDL_QUIT)
                    quit = true;

                // Handle movement of the square
                if (e.type == SDL_KEYDOWN)
                {
                    switch (e.key.keysym.sym)
                    {
                    case SDLK_UP:
                        if (squareRect.y > 0 && mover.canMoveUp())
                            squareRect.y -= 5;
                        break;

                    case SDLK_DOWN:
                        if (squareRect.y < SCREEN_HEIGHT - SQUARE_HEIGHT
                            && mover.canMoveDown())
                            squareRect.y += 5;
                        break;

                    case SDLK_LEFT:
                        if (squareRect.x > 0 && mover.canMoveLeft())
                            squareRect.x -= 5;
                        break;

                    case SDLK_RIGHT:
                        if (squareRect.x < SCREEN_WIDTH - SQUARE_WIDTH
                            && mover.canMoveRight())
                            squareRect.x += 5;
                        break;
                    }
                }

                // Initialize renderer color white for the background
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

                // Clear screen
                SDL_RenderClear(renderer);

                // Set renderer color red to draw the square
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

                // Draw filled square
                SDL_RenderFillRect(renderer, &squareRect);

                // Drawing the obstacles
                drawObstacles(renderer);

                // Update screen
                SDL_RenderPresent(renderer);
            }

            // Destroy renderer
            SDL_DestroyRenderer(renderer);
        }

        // Destroy window
        SDL_DestroyWindow(window);
    }

    // Quit SDL
    SDL_Quit();

    return 0;
}

std::vector<SDL_Rect> createObstacles()
{
    std::vector<SDL_Rect> obstacles;

    // Obstacle 1
    SDL_Rect obstacle1;

    obstacle1.w = 20;
    obstacle1.h = 140;

    obstacle1.x = (SCREEN_WIDTH / 2) + 80;
    obstacle1.y = SCREEN_HEIGHT / 2 - obstacle1.h / 2;

    obstacles.push_back(obstacle1);

    // Obstacle 2
    SDL_Rect obstacle2;

    obstacle2.w = 80;
    obstacle2.h = 40;

    obstacle2.x = (SCREEN_WIDTH / 2) - 280;
    obstacle2.y = SCREEN_HEIGHT / 2 - obstacle2.h / 2;

    obstacles.push_back(obstacle2);

    // Obstacle 3
    SDL_Rect obstacle3;

    obstacle3.w = 75;
    obstacle3.h = 75;

    obstacle3.x = (SCREEN_WIDTH / 2) - 280;
    obstacle3.y = 120;

    obstacles.push_back(obstacle3);

    // Obstacle 4
    SDL_Rect obstacle4;

    obstacle4.w = 140;
    obstacle4.h = 20;

    obstacle4.x = (SCREEN_WIDTH / 2) - 200;
    obstacle4.y = 450;

    obstacles.push_back(obstacle4);

    return obstacles;
}

void drawObstacles(SDL_Renderer* renderer)
{
    // Using the black color to render the obstacles
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Rendering all the obstacles
    for (const SDL_Rect& obstacle : obstacles)
        SDL_RenderFillRect(renderer, &obstacle);
}