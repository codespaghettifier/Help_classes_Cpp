#include "../include/Vector2D.h"
#include <cmath>
#include <iostream>
#include <utility>

int Vector2D::count = 0;

Vector2D Vector2D::fromCarthesian(double x, double y)
{
	return Vector2D(x, y);
}

Vector2D Vector2D::fromPolar(double r, double phi)
{
	return Vector2D(r * cos(phi * M_PI / 180), r * sin(phi * M_PI / 180));
}

Vector2D Vector2D::add(const Vector2D &other) const 
{
	return Vector2D(x + other.x, y + other.y);
}

double Vector2D::dot(const Vector2D &other) const
{
	return x * other.x + y * other.y;
}

void Vector2D::print(std::string str) const
{
	std::cout<<str<<"("<< x << ", "<< y <<")"<< std::endl;
}

Vector2D::Vector2D(Vector2D&& other)
: x(std::exchange(other.x, 0))
, y(std::exchange(other.y, 0))
{
	count++;
  print("moving: ");
}

Vector2D::Vector2D(const Vector2D& other)
: Vector2D(other.x, other.y) {
  print("copying: ");
}

Vector2D::~Vector2D() {
   count --;
}

Vector2D::Vector2D(double x, double y)
:x(x)
,y(y) 
{
	count++;
}