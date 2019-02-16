#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape2D.h"
class Rectangle:public Shape2D {
public:
	Rectangle(double l,double w) : length(l),width(w) {}
	Rectangle(double l,double w, double x, double y) :
		Shape2D(x, y), length(l), width(w) {}
	double getCircumference() const override {
		return 2 * (length + width);
	}
	double getArea() const override {
		return length * width;
	}
	double getLength() const {
		return length;
	}
	double getWidth() const {
		return width;
	}
private:
	double length;
	double width;
};
#endif