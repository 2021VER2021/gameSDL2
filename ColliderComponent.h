#pragma once

#include "Components.h"
#include <string>

class ColliderComponent : public Component
{
private:

public:
    SDL_Rect collider;
    std::string tag;

    TransformComponent* transform;
    ColliderComponent(std::string t)
    {
        tag = t;
    }
    ~ColliderComponent() = default;

    void init() override
    {
        if (!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override
    {
        collider.x = transform->x();
        collider.y = transform->y();
        collider.w = transform->getWidth() * transform->getScale();
        collider.h = transform->getHeight() * transform->getScale();
    }

    void draw() override
    {

    }
};