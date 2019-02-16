#ifndef SHAPE3D_H
#define SHAPE3D_H
#include "Shape.h"
class Shape3D:public Shape{
public:
	Shape3D() = default;
	Shape3D(double x, double y, double z) :
		Shape(x, y), pointZ(z) {}
	double getPointZ() const {
		return pointZ;
	}
	virtual double getVolume() const = 0;
	virtual double getSurfaceArea() const = 0;
protected:
	double pointZ = 0.0;
};
#endif