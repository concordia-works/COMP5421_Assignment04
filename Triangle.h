#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
class Triangle : public Shape {
protected:
	int base;
	int height;
	virtual int getHeightBBox() const override;
	virtual int getWidthBBox() const override;
	virtual void setBase(const unsigned int&) = 0;
public:
	Triangle(const string&, const string&);
	virtual ~Triangle();
	virtual int getWidth() const override;
	virtual int getBase() const;
	virtual int getHeight() const override;
	virtual void scale(const int&) = 0;
	virtual double getGeoArea() const override;
	virtual int getScreenArea() const = 0;
	virtual double getGeoPerimeter() const = 0;
	virtual int getScreenPerimeter() const = 0;
	virtual vector<vector<char>> draw(char, char) const = 0;
};

#endif