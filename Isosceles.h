#ifndef ISOSCELES_H
#define ISOSCELES_H

#include "Triangle.h"

class Isosceles : public Triangle {
public:
	explicit Isosceles(const unsigned int& = 1, const string& = "Generic Isosceles");
	~Isosceles();
	virtual void setBase(const unsigned int&) override;
	virtual void scale(const int&) override;
	virtual int getScreenArea() const override;
	virtual double getGeoPerimeter() const override;
	virtual int getScreenPerimeter() const override;
	virtual vector<vector<char>> draw(char = '*', char = ' ') const override;
};

#endif