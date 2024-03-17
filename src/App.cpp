#include "App.hpp"
#include "Globals.hpp"
#include "precompiled.hpp"
#include "DebugInfo.hpp"

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

    const int desired_fps = gTargetFPS;
    int last_ticks = SDL_GetTicks();
    Uint64 startTime;
    Uint64 endTime;

    while (!quit)
    {
        startTime = SDL_GetPerformanceCounter();
        if (SDL_GetTicks() - last_ticks < 1000 / desired_fps)
        {
            continue;
        }
        last_ticks = SDL_GetTicks();
        input_handler(event, quit);

        SDL_RenderClear(glRenderer);
        draw();
        SDL_RenderPresent(glRenderer);
        endTime = SDL_GetPerformanceCounter();
        gDeltaTime = static_cast<float>(endTime - startTime) / SDL_GetPerformanceFrequency() * 1000.0;
    }
}

void App::draw()
{
    gBoard->drawBoard();

    drawDebugInfo();
}

void App::input_handler(SDL_Event &event, bool &quit)
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            quit = true;
        }

        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            int x = event.button.x;
            int y = event.button.y;
            std::cout << "X: " << x << " Y: " << y << std::endl;
            std::cout << "Mark: " << gBoard->getMark(x, y) << std::endl;
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
}

int App::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    if (TTF_Init() != 0)
    {
        std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
        return -1;
    }

    gWindow = SDL_CreateWindow("Velha", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gWinWidth, gWinHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (gWindow == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    glRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

    if (glRenderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    gDebugFont = TTF_OpenFont("assets/ttf/FiraCode.ttf", 16);
    if (gDebugFont == nullptr)
    {
        std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
        return -1;
    }

    gBoard = new Board();

    return 0;
}
