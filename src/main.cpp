#include "Globals.hpp"
#include "App.hpp"
#include "precompiled.hpp"

int main(int argc, char *argv[])
{
    if (App::init() != 0)
    {
        std::cout << "Failed to initialize!" << std::endl;
        return -1;
    }
    App::run();
    App::deinit();

    return 0;
}
