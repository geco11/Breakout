#include "DualVector.h"

DualVector::DualVector(float x, float y)
{
    setCartesian(x, y);
}

DualVector& DualVector::setCartesian(float x, float y)
{
    this->x = x;
    this->y = y;
    return *this;
}

DualVector& DualVector::setPolar(float len, float phi)
{
    float t = deg_to_rad(phi);
    y = len * sin(t);
    x = len * cos(t);
    return *this;
}

float DualVector::getLen() const
{
    return sqrt(x * x + y * y);
}

float DualVector::getPhi() const
{
    return rad_to_deg(atan2f(y, x));
}

DualVector& DualVector::setPhi(float phi)
{
    setPolar(getLen(), phi);
    return *this;
}

sf::Vector2f DualVector::tosf() const
{
    return sf::Vector2f(x, y);
}


DualVector DualVector::operator+(const DualVector& other) const
{
    DualVector res;
    res.setCartesian(x + other.x, y + other.y);

    return res;
}

DualVector DualVector::operator+(const sf::Vector2f& other) const
{
    DualVector res;
    res.setCartesian(x + other.x, y + other.y);
    return res;

}

DualVector DualVector::operator-(const DualVector& other) const
{
    DualVector res;
    res.setCartesian(x - other.x, y - other.y);

    return res;
}

DualVector DualVector::operator-(const sf::Vector2f& other) const
{
    DualVector res;
    res.setCartesian(x - other.x, y - other.y);
    return res;
}

DualVector DualVector::operator*(float x) const
{
    DualVector res;
    res.setCartesian(this->x * x, y * x);

    return res;
}

DualVector DualVector::operator*(const sf::Vector2f& other) const
{
    DualVector res;
    res.setCartesian(x * other.x, y * other.y);
    return res;
}

DualVector DualVector::operator/(float x) const
{
    DualVector res;
    res.setCartesian(this->x / x, y / x);

    return res;
}

DualVector DualVector::operator/(const sf::Vector2f& other) const
{
    DualVector res;
    res.setCartesian(x / other.x, y / other.y);
    return res;
}

float DualVector::rad_to_deg(float rad)
{
    return rad * 57.2958f;
}

float DualVector::deg_to_rad(float deg)
{
    return deg / 57.2958f;
}