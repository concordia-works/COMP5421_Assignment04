#include "Triangle.h"

int Triangle::getHeightBBox() const {
	return height;
}

int Triangle::getWidthBBox() const {
	return base;
}

Triangle::Triangle(const string& gName, const string& dName) : Shape(gName, dName) {}

Triangle::~Triangle() {}

int Triangle::getWidth() const {
	return getBase();
}

int Triangle::getBase() const {
	return base;
}

int Triangle::getHeight() const {
	return height;
}

double Triangle::getGeoArea() const {
	return (height * base) / (double) 2;
}
