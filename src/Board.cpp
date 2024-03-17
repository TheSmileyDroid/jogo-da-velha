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

void drawSphere(SDL_Renderer *glRenderer, int x, int y)
{
    SDL_Point points[9];
    for (int i = 0; i < 9; i++)
    {
        points[i].x = x + cos(2 * M_PI * i / 8) * 10;
        points[i].y = y + sin(2 * M_PI * i / 8) * 10;
    }
    SDL_RenderDrawLines(glRenderer, points, 9);
}

void drawX(SDL_Renderer *glRenderer, int x, int y)
{
    SDL_RenderDrawLine(glRenderer, x - 5, y - 5, x + 5, y + 5);
    SDL_RenderDrawLine(glRenderer, x - 5, y + 5, x + 5, y - 5);
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
            SDL_Rect rect = {boardArea.x + j * (boardArea.w / 3) + padding, boardArea.y + i * (boardArea.h / 3) + padding, boardArea.w / 3 - padding * 2, boardArea.h / 3 - padding * 2};
            SDL_RenderDrawRect(glRenderer, &rect);
            if (board[i][j] == 1)
            {
                drawX(glRenderer, boardArea.x + j * (boardArea.w / 3) + boardArea.w / 6, boardArea.y + i * (boardArea.h / 3) + boardArea.h / 6);
            }
            if (board[i][j] == 2)
            {
                drawSphere(glRenderer, boardArea.x + j * (boardArea.w / 3) + boardArea.w / 6, boardArea.y + i * (boardArea.h / 3) + boardArea.h / 6);
            }
            SDL_SetRenderDrawColor(glRenderer, 0, 0, 255, 255);
        }
    }

    SDL_SetRenderDrawColor(glRenderer, 0, 0, 0, 255);
}

void Board::markX(int x, int y)
{
    if (x < boardArea.x || x > boardArea.x + boardArea.w)
    {
        throw std::out_of_range("X out of bounds");
    }
    if (y < boardArea.y || y > boardArea.y + boardArea.h)
    {
        throw std::out_of_range("Y out of bounds");
    }
    boardCoord(x, y) = 1;
}

int &Board::boardCoord(int x, int y)
{
    return board[static_cast<int>((y - boardArea.y) / (boardArea.h / 3))][static_cast<int>((x - boardArea.x) / (boardArea.w / 3))];
}

/**
 * Retrieves the mark at the specified coordinates on the board.
 *
 * @param x the x-coordinate
 * @param y the y-coordinate
 *
 * @return the mark at the specified coordinates, or -1 if the coordinates are out of bounds
 */
int Board::getMark(int x, int y)
{
    if (x < boardArea.x || x > boardArea.x + boardArea.w)
    {
        return -1;
    }
    if (y < boardArea.y || y > boardArea.y + boardArea.h)
    {
        return -1;
    }

    return boardCoord(x, y);
}

void Board::markO(int x, int y)
{
    if (x < boardArea.x || x > boardArea.x + boardArea.w)
    {
        throw std::out_of_range("X out of bounds");
    }
    if (y < boardArea.y || y > boardArea.y + boardArea.h)
    {
        throw std::out_of_range("Y out of bounds");
    }
    boardCoord(x, y) = 2;
}
