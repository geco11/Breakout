#pragma once
#include <cmath>
#include <sfml/Graphics.hpp>


class DualVector {


public:
	DualVector() = default;
	float x = 0, y = 0;
	DualVector(float x, float y);
	DualVector& setCartesian(float x, float y);
	DualVector& setPolar(float len, float phi);
	DualVector& setPhi(float phi);

	float getLen() const;
	float getPhi() const;

	sf::Vector2f tosf() const;
	DualVector operator+(const DualVector& other) const;
	DualVector operator+(const sf::Vector2f& other) const;
	DualVector operator-(const DualVector& other) const;
	DualVector operator-(const sf::Vector2f& other) const;
	DualVector operator*(float x) const;
	DualVector operator*(const sf::Vector2f& other) const;
	DualVector operator/(float x) const;
	DualVector operator/(const sf::Vector2f& other) const;

	static float rad_to_deg(float rad);
	static float deg_to_rad(float deg);
};