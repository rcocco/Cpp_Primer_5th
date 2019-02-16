#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Sphere.h"
#include "Cone.h"
#include "Shape2D.h"
#include "Shape3D.h"
using std::cout;
using std::endl;
int main() {
	Circle circle(5);
	Rectangle rect(5, 2);
	Sphere sphere(5);
	Cone cone(5,2);
	Shape2D *shape2d = &circle;
	cout << shape2d->getCircumference() << endl;
	shape2d = &rect;
	cout << shape2d->getArea() << endl;
	Shape3D *shape3d = &sphere;
	cout << shape3d->getVolume() << endl;
	shape3d = &cone;
	cout << shape3d->getSurfaceArea() << endl;
	return 0;
}