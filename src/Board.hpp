#pragma once

#include "precompiled.hpp"

class Board
{

public:
    Board();
    ~Board();
    void drawBoard();
    void markX(int x, int y);
    int &boardCoord(int x, int y);
    void markO(int x, int y);
    int getMark(int x, int y);

private:
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    SDL_Rect boardArea = {100, 100, 300, 300};
};
