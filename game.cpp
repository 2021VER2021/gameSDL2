#include "game.hpp"
#include "object.hpp"
#include "Components.h"
#include "textureManager.hpp"
#include "Collision.h"
#include "Map.h"

Manager manager;
Map *map = nullptr;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

SDL_Rect Game::camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

auto& player2(manager.addEntity());

/* groups of objects */
enum groupLabels : std::size_t
{
    groupMap,
    groupPlayers,
    groupEnemies,
    groupColliders,
    groupProjectiles
};

std::vector<Entity*>& Game::tiles = manager.getGroup(groupMap);
std::vector<Entity*>& Game::players = manager.getGroup(groupPlayers);
std::vector<Entity*>& Game::enemies = manager.getGroup(groupEnemies);
std::vector<Entity*>& Game::colliders = manager.getGroup(groupColliders);

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

     if( SDL_Init( SDL_INIT_EVERYTHING ) == 0 )
    {
        std::cout << "subsistems initialised... " << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window){
            std::cout << "Window created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 200);
            std::cout << "Renderer created" << std::endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }
    map = new Map();

    //ecs

    Map::LoadMap("assets/map_1_16x16.txt", 32, 16);

    player2.addComponent<TransformComponent>(0, 200, 32, 32, 2);
    player2.addComponent<SpriteComponent>("assets/dog_3x4_32x32.png", true);
    player2.addComponent<ControlComponent>();
    player2.addComponent<ColliderComponent>("player");
    player2.addGroup(groupPlayers);

    tiles = manager.getGroup(groupMap);
    players = manager.getGroup(groupPlayers);
    enemies = manager.getGroup(groupEnemies);
    colliders = manager.getGroup(groupColliders);
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}
void Game::update()
{
    manager.refresh();
    manager.update();

    camera.x = player2.getComponent<TransformComponent>().pos.x - SCREEN_WIDTH / 2;
    camera.y = player2.getComponent<TransformComponent>().pos.y - SCREEN_HEIGHT / 2;

    if (camera.x < 0) camera.x = 0;
    if (camera.y < 0) camera.y = 0;
    if (camera.x > camera.w) camera.x = camera.w;
    if (camera.y > camera.h) camera.y = camera.h;

    for (auto c: colliders)
    {
    if (Collision::AABB(player2.getComponent<ColliderComponent>().collider,
     c->getComponent<ColliderComponent>().collider))
    {
        player2.getComponent<TransformComponent>().velocity *(-1);
    }
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    for (auto& t: tiles) t->draw();
    for (auto& t: players) t->draw();
    for (auto& t: enemies) t->draw();
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "QUIT" << std::endl;
}

void Game::AddTile(int id, int x, int y)
{
    auto& tile(manager.addEntity());
    tile.addComponent<TransformComponent>(x, y, 32, 32, 1); //FIXIT
    tile.addComponent<TileComponent>(0, 0, x, y, id); //FIXIT
    tile.addGroup(groupMap);
}

void Game::AddCollideTile(int id, int x, int y, std::string tag)
{
    auto& tile(manager.addEntity());
    tile.addComponent<TransformComponent>(x, y, 32, 32, 1); //FIXIT
    tile.addComponent<TileComponent>(0, 0, x, y, id);
    tile.addComponent<ColliderComponent>(tag);
    tile.addGroup(groupMap);
    tile.addGroup(groupColliders);
}

bool Game::running(){
    return isRunning;
}