#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape2D.h"
class Circle:public Shape2D {
public:
	Circle(double r) : radius(r) {}
	Circle(double r, double x, double y) :
		Shape2D(x, y), radius(r) {}
	double getCircumference() const override {
		return 2 * radius * PI;
	}
	double getArea() const override {
		return radius * radius * PI;
	}
	double getRadius() const {
		return radius;
	}
private:
	double radius;
};
#endif