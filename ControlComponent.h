#pragma once

#include "Components.h"

class ControlComponent : public Component
{
public:
    TransformComponent* transform;
    SpriteComponent* sprite;

    ControlComponent() = default;
    ~ControlComponent() = default;
    void init() override
    {
        if (!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }
        if (!entity->hasComponent<SpriteComponent>())
        {
            entity->addComponent<SpriteComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }

    void draw() override
    {

    }

    void update() override
    {
        if (Game::event.type == SDL_KEYDOWN)
        {
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_w:
                transform->setVelocity(transform->getVelocity().x, -1);
                sprite->Play("Walk");
                break;
            case SDLK_s:
                transform->setVelocity(transform->getVelocity().x, 1);
                sprite->Play("Walk");
                break;
            case SDLK_a:
                transform->setVelocity(-1, transform->getVelocity().y);
                sprite->Play("Walk");
                sprite->spriteFlip = SDL_FLIP_NONE;
                break;
            case SDLK_d:
                transform->setVelocity(1, transform->getVelocity().y);
                sprite->Play("Walk");
                sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
                break;
            default:
                break;
            }
        }
        if (Game::event.type == SDL_KEYUP)
        {
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_w:
                transform->setVelocity(transform->getVelocity().x, 0);
                sprite->Play("Idle");
                break;
            case SDLK_s:
                transform->setVelocity(transform->getVelocity().x, 0);
                sprite->Play("Idle");
                break;
            case SDLK_a:
                transform->setVelocity(0, transform->getVelocity().y);
                sprite->Play("Idle");
                break;
            case SDLK_d:
                transform->setVelocity(0, transform->getVelocity().y);
                sprite->Play("Idle");
                break;
            default:
                break;
            }
        }
    }
private:
    SDL_Event event;
};