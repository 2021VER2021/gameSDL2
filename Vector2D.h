#pragma once

class Vector2D
{
public:
    float x;
    float y;

    Vector2D();
    Vector2D(float, float);

    Vector2D& Add(const Vector2D& v);
    Vector2D& Subtract(const Vector2D& v);
    Vector2D& Multiply(const Vector2D& v);
    Vector2D& Divide(const Vector2D& v);

    friend Vector2D& operator+ (Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator- (Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator* (Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator/ (Vector2D& v1, const Vector2D& v2);

    Vector2D& operator+= (const Vector2D& v);
    Vector2D& operator*= (const Vector2D& v);
    Vector2D& operator-= (const Vector2D& v);
    Vector2D& operator/= (const Vector2D& v);

    friend Vector2D& operator* (Vector2D& v, const int& c);
    friend Vector2D& operator* (Vector2D& v, const float& c);

    void Zero();
    
    float Dot(Vector2D& v);
};

