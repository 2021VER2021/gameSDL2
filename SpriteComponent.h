#pragma once
#include "textureManager.hpp"
#include "Components.h"
#include "Vector2D.h"
#include "Animation.h"
#include <map>

class SpriteComponent : public Component
{
private:
    TransformComponent* position;
    SDL_Texture* texture; 

    bool animated = false;
    int frames = 0;
    int speed = 100; // delay

public:
    SDL_Rect srcRect, destRect;

    int animIndex = 0;

    std::map<const char*, Animation> animations;

    SDL_RendererFlip spriteFlip = SDL_FLIP_HORIZONTAL;

    SpriteComponent() = default;
    SpriteComponent(const char* path)
    {
        setTexture(path);
    }
    SpriteComponent(const char* path, bool isAnimated)
    {
        animated = isAnimated;

        Animation idle = Animation(0, 3, 100);
        Animation walk = Animation(1, 4, 100);

        animations.emplace("Idle", idle); // FIXIT
        animations.emplace("Walk", walk);

        Play("Idle");

        setTexture(path);
    }

    ~SpriteComponent()
    {
        SDL_DestroyTexture(texture);
    }

    void setTexture(const char* path)
    {
        texture = TextureManager::LoadTexture(path);
    }

    void init() override
    {
        if (!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }
        position = &entity->getComponent<TransformComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = position->getWidth();
        srcRect.h = position->getHeight();

    }

    void update() override
    {

        if (animated)
        {
            srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
        }

        srcRect.y = animIndex * position->getHeight();

        destRect.x = position->x() - Game::camera.x;
        destRect.y = position->y() - Game::camera.y;
        destRect.w = position->getWidth() * position->getScale();
        destRect.h = position->getHeight() * position->getScale();
    }

    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
    }

    void Play(const char* animName)
    {
        frames = animations[animName].frames;
        animIndex = animations[animName].index;
        speed = animations[animName].speed;
    }
};