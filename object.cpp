#include "object.hpp"
#include "textureManager.hpp"

VisualObject::VisualObject(){}

void VisualObject::init(SDL_Renderer* r, const char* texture, int posx, int posy, int width, int height)
{
    tex = TextureManager::LoadTexture(texture);
    ren = r;
    rect = new SDL_Rect;
    rect->x = posx; rect->y = posy;
    rect->h = height; rect->w = width;
    isInit = true;
}

VisualObject::~VisualObject()
{
    if (isInit)
    {
        SDL_DestroyTexture(tex);
        delete rect;
    } 
}

void VisualObject::draw(int posx, int posy, int w, int h) // FIXIT - every time creating dest_rect
{      
    SDL_Rect *tmp = new SDL_Rect;
    tmp->x = posx; tmp->y = posy;
    tmp->w = w; tmp->h = h;
    SDL_RenderCopy(ren, tex, rect, tmp);
    delete tmp;
}

void VisualObject::update(){} //FIXIT

/* VisualObject class, for basic objects, that needs to be displayed on screen */