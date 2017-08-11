#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
	int width; // >= 1
	int height; // >= 1
	virtual int getHeightBBox() const override;
	virtual int getWidthBBox() const override;
public:
	explicit Rectangle(const unsigned int& = 1, const unsigned int& = 1, const string& = "Generic Rectangle");
	~Rectangle();
	virtual int getWidth() const override;
	virtual int getHeight() const override;
	void setWidth(const unsigned int&);
	void setHeight(const unsigned int&);
	virtual void scale(const int&) override;
	virtual double getGeoArea() const override;
	virtual int getScreenArea() const override;
	virtual double getGeoPerimeter() const override;
	virtual int getScreenPerimeter() const override;
	virtual vector<vector<char>> draw(char = '*', char = ' ') const override;
};

#endif