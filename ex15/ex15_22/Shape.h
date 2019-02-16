#ifndef SHAPE_H
#define SHAPE_H
class Shape {
public:
	Shape() = default;
	Shape(double x,double y):pointX(x),pointY(y){}
	double getPointX() const {
		return pointX;
	}
	double getPointY() const {
		return pointY;
	}
	virtual ~Shape() = default;
protected:
	double pointX = 0.0;
	double pointY = 0.0;
	static const double PI;
};
#endif