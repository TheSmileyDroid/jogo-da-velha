#include "App.hpp"
#include "Globals.hpp"
#include <SDL2/SDL_render.h>
#include <iostream>

void App::deinit()
{
    SDL_DestroyRenderer(glRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

void App::run()
{
    SDL_Event event;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x = event.button.x / (gWinWidth / 3);
                int y = event.button.y / (gWinHeight / 3);
                if (gBoard->getMark(x, y) == 0)
                {
                    if (gTurn % 2 == 0)
                    {
                        gBoard->markX(x, y);
                    }
                    else if (gTurn % 2 == 1)
                    {
                        gBoard->markO(x, y);
                    }

                    gTurn++;
                }
            }
        }

        SDL_RenderClear(glRenderer);
        gBoard->drawBoard();
        SDL_RenderPresent(glRenderer);
    }
}

void App::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }

    gWindow = SDL_CreateWindow("Velha", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gWinWidth, gWinHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (gWindow == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    }

    glRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

    if (glRenderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    }

    gBoard = new Board();
}
