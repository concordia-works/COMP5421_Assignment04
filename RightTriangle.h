#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle {
public:
	explicit RightTriangle(const unsigned int& = 1, const string& = "Generic RightTriangle");
	~RightTriangle();
	virtual void setBase(const unsigned int&) override;
	virtual void scale(const int&) override;
	virtual int getScreenArea() const override;
	virtual double getGeoPerimeter() const override;
	virtual int getScreenPerimeter() const override;
	virtual vector<vector<char>> draw(char = '*', char = ' ') const override;
};

#endif