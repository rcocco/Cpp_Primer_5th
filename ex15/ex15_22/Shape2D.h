#ifndef SHAPE2D_H
#define SHAPE2D_H
#include "Shape.h"
class Shape2D:public Shape {
public:
	Shape2D() = default;
	Shape2D(double x, double y) :Shape(x, y) {}
	virtual double getCircumference() const = 0;
	virtual double getArea() const = 0;
};
#endif