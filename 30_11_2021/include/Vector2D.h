#pragma once

#include <string>

class Vector2D
{
public:
	static int count;

	static Vector2D fromCarthesian(double, double);
	static Vector2D fromPolar(double, double);
	Vector2D add(const Vector2D &other) const;
	double dot(const Vector2D &other) const;
  	void print(std::string str) const;

	Vector2D(Vector2D&& other);
	Vector2D(const Vector2D& other);
	~Vector2D();

private:
	double x;
	double y;
	
  Vector2D(double x, double y);
};
