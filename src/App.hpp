#pragma once

class App
{
public:
    static int init();
    static void deinit();
    static void run();
    static void draw();
    static void input_handler(SDL_Event &event, bool &quit);
};
