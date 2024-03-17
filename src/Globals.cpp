#include "Globals.hpp"

int gWinWidth = 500;
int gWinHeight = 500;
SDL_Window *gWindow = nullptr;
SDL_Renderer *glRenderer = nullptr;

Board *gBoard = nullptr;

int gTurn = 0;

float gTargetFPS = 30;

float gDeltaTime = 0.0f;

TTF_Font *gDebugFont = nullptr;