#include "DebugInfo.hpp"
#include "Globals.hpp"
#include "precompiled.hpp"

void drawDebugInfo()
{
    SDL_SetRenderDrawColor(glRenderer, 255, 255, 255, 50);
    SDL_SetRenderDrawBlendMode(glRenderer, SDL_BLENDMODE_BLEND);

    std::string debugText = "FPS: " + std::to_string(gTargetFPS) + "\nTurn: " + std::to_string(gTurn) + "\nDelta: " + std::to_string(gDeltaTime);

    int wrap = 200;

    SDL_Surface *text = TTF_RenderText_Solid_Wrapped(gDebugFont, debugText.c_str(), {255, 255, 255, 255}, wrap);

    float textWidth = (float)text->w;
    float textHeight = (float)text->h;

    SDL_Rect rect = {0, 0, wrap, text->h};

    SDL_RenderFillRect(glRenderer, &rect);

    SDL_SetRenderDrawColor(glRenderer, 255, 255, 255, 255);

    SDL_FRect textRect = {0.0f, 0.0f, textWidth, textHeight};

    auto texture = SDL_CreateTextureFromSurface(glRenderer, text);

    SDL_RenderCopyF(glRenderer, texture, nullptr, &textRect);

    SDL_DestroyTexture(texture);

    SDL_FreeSurface(text);

    SDL_SetRenderDrawColor(glRenderer, 0, 0, 0, 255);
}