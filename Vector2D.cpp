#include "Vector2D.h"

void Vector2D::Zero()
{
    this->x = 0;
    this->y = 0;
}

Vector2D::Vector2D()
{
    this->Zero();
}

Vector2D::Vector2D(float x, float y): x(x), y(y) {}

Vector2D& Vector2D::Add(const Vector2D& v)
{
    this->x+= v.x;
    this->y+= v.y;
    return *this;
}
Vector2D& Vector2D::Subtract(const Vector2D& v)
{
    this->x-= v.x;
    this->y-= v.y;
    return *this;
}
Vector2D& Vector2D::Multiply(const Vector2D& v)
{
    this->x*= v.x;
    this->y*= v.y;
    return *this;
}
Vector2D& Vector2D::Divide(const Vector2D& v)
{
    this->x/= v.x;
    this->y/= v.y;
    return *this;
}

Vector2D& operator+ (Vector2D& v1, const Vector2D& v2)
{
    return v1.Add(v2);
}
Vector2D& operator- (Vector2D& v1, const Vector2D& v2)
{
    return v1.Subtract(v2);
}
Vector2D& operator* (Vector2D& v1, const Vector2D& v2)
{
    return v1.Multiply(v2);
}
Vector2D& operator/ (Vector2D& v1, const Vector2D& v2)
{
    return v1.Divide(v2);
}

Vector2D& Vector2D::operator+= (const Vector2D& v)
{
    return this->Add(v);
}
Vector2D& Vector2D::operator-= (const Vector2D& v)
{
    return this->Subtract(v);
}
Vector2D& Vector2D::operator*= (const Vector2D& v)
{
    return this->Multiply(v);
}
Vector2D& Vector2D::operator/= (const Vector2D& v)
{
    return this->Divide(v);
}

Vector2D& operator* (Vector2D& v, const int& c)
{
    v.x *= c;
    v.y *= c;
    return v;
}
Vector2D& operator* (Vector2D& v, const float& c)
{
    v.x *= c;
    v.y *= c;
    return v;
}
float Vector2D::Dot(Vector2D& v)
{
    return this->x*v.x + this->y*v.y;
}
