#ifndef CONE_H
#define CONE_H
#include "Shape3D.h"
#include <cmath>
class Cone:public Shape3D {
public:
	Cone(double r,double h) :radius(r), height(h){}
	Cone(double r, double h,double x, double y, double z) :
		Shape3D(x, y, z), radius(r), height(h){}
	double getVolume() const override {
		return PI * radius * radius * height / 3;
	}
	double getSurfaceArea() const override {
		return PI * radius * (radius + 
			std::sqrt(height * height + radius * radius));
	}
	double getRadius() const {
		return radius;
	}
	double getHeight() const {
		return height;
	}
private:
	double radius;
	double height;
};
#endif