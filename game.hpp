#ifndef game_hpp
#define game_hpp


#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Entity;

class Game{
public:
    Game();
    ~Game();

    void init(const char*, int, int, int, int, bool);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();

    static void AddTile(int id, int x, int y);
    static void AddCollideTile(int id, int x, int y, std::string tag);

    static std::vector<Entity*>& tiles;
    static std::vector<Entity*>& players;
    static std::vector<Entity*>& enemies;
    static std::vector<Entity*>& colliders;

    static SDL_Renderer *renderer;
    static SDL_Event event;
    static SDL_Rect camera;

private:
    bool isRunning;
    SDL_Window *window;
};

#endif /* game.hpp */