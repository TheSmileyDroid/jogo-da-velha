#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Board.hpp"

extern int gWinWidth;
extern int gWinHeight;

extern SDL_Window *gWindow;
extern SDL_Renderer *glRenderer;

extern Board *gBoard;

extern int gTurn;

extern float gTargetFPS;

extern float gDeltaTime;

extern TTF_Font *gDebugFont;
