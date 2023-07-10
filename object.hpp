#pragma once

#include "game.hpp"

class VisualObject
{
    public:
        VisualObject();
        ~VisualObject();
        void draw(int, int, int, int);
        void init(SDL_Renderer*, const char*, int, int, int, int);
        void update();
    private:
        bool isInit;
        SDL_Rect *rect;
        SDL_Renderer *ren;
        SDL_Texture *tex;
};