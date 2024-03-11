#include "Board.hpp"
#include "Globals.hpp"

Board::Board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }
}

Board::~Board()
{
}

void Board::drawBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            SDL_SetRenderDrawColor(glRenderer, 255, 255, 255, 255);
            if (board[i][j] == 1)
            {
                SDL_SetRenderDrawColor(glRenderer, 0, 0, 255, 255);
            }
            if (board[i][j] == 2)
            {
                SDL_SetRenderDrawColor(glRenderer, 255, 0, 0, 255);
            }
            const int padding = 10;
            SDL_Rect rect = {i * gWinWidth / 3 + padding, j * gWinHeight / 3 + padding, (gWinWidth / 3) - padding * 2, (gWinHeight / 3) - padding * 2};
            SDL_RenderDrawRect(glRenderer, &rect);
        }
    }

    SDL_SetRenderDrawColor(glRenderer, 0, 0, 0, 255);
}

void Board::markX(int x, int y)
{
    board[x][y] = 1;
}

int Board::getMark(int x, int y)
{
    return board[x][y];
}

void Board::markO(int x, int y)
{
    board[x][y] = 2;
}
