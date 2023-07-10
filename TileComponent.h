#pragma once

#include "Components.h"
#include "textureManager.hpp"

class TileComponent : public Component
{
public:
    SDL_Texture* texture;
    SDL_Rect sRect, dRect;
    Vector2D position;
    int tileId;
    const char* path;
    TransformComponent* pos;

    TileComponent() = default;

    TileComponent(int srcX, int srcY, int posX, int posY, int id)
    {
        position.x = posX;
        position.y = posY;
        tileId = id;

        sRect.x = srcX;
        sRect.y = srcY;

        sRect.w = sRect.h = 32;

        dRect.x = posX;
        dRect.y = posY;
        dRect.w = dRect.h = 32; //any scale

        switch (tileId)
        {
        case 1:
            path = "assets/dirt.png";
            break;
        case 2:
            path = "assets/wood.png";
            break;
        case 3: 
            path = "assets/blueFlower.png";
            break;
        case 4: 
            path = "assets/pinkFlower.png";
            break;
        default:
            break;
        }
        texture = TextureManager::LoadTexture(path);
    }

    void init() override
    {
        pos = &entity->getComponent<TransformComponent>();
    }

    void draw() override
    {
        TextureManager::Draw(texture, sRect, dRect, SDL_FLIP_NONE);
    }

    void update() override
    {
        dRect.x = position.x - Game::camera.x;
        dRect.y = position.y - Game::camera.y;
    }

};