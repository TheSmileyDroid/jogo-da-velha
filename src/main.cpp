#include "Globals.hpp"
#include "App.hpp"
#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    App::init();
    App::run();
    App::deinit();

    return 0;
}
