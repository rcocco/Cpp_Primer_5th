#ifndef SPHERE_H
#define SPHERE_H
#include "Shape3D.h"
class Sphere:public Shape3D {
public:
	Sphere(double r) :radius(r) {}
	Sphere(double r,double x,double y,double z):
		Shape3D(x,y,z),radius(r){}
	double getVolume() const override {
		return radius * radius * radius * PI * 4 / 3;
	}
	double getSurfaceArea() const override {
		return 4 * radius * radius * PI;
	}
	double getRadius() const {
		return radius;
	}
private:
	double radius;
};
#endif