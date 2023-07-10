#pragma once
#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
private:
    
public:
    /* These fields might me private, but i am tired*/
    Vector2D pos;
    Vector2D velocity;
    Vector2D acceleration;
    float speed = 1;

    int height = 32;
    int width = 32;
    int scale = 1;

    ~TransformComponent() = default;
    TransformComponent()
    {
        pos.Zero();
        velocity.Zero();
        acceleration.Zero();
    };
    TransformComponent(int x, int y)
    {
        pos.x = x;  pos.y = y;
    }
    TransformComponent(int x, int y, int h, int w, int s)
    {
        pos.x = x;  pos.y = y;
        height = h; width = w; scale = s;
    }
    int x() {return static_cast<int>(pos.x);}
    int y() {return static_cast<int>(pos.y);}

    void init() override
    {
        velocity.Zero();
        acceleration.Zero();
    }

    void update() override
    {
        pos += velocity*speed + acceleration * (speed*speed/2);
        velocity += acceleration * speed;
    }

    void setPos(float x, float y)
    {
        pos.x = x;
        pos.y = y;
    }
    void setVelocity(float x, float y)
    {
        velocity.x = x;
        velocity.y = y;
    }
    void setAcceleration(float x, float y)
    {
        acceleration.x = x;
        acceleration.y = y;
    } 
    Vector2D& getVelocity()
    {
        return velocity;
    }
    Vector2D& getPosition()
    {
        return pos;
    }
    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }
    int getScale()
    {
        return scale;
    }
    void draw() override
    {

    }
};

