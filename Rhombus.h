#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Shape.h"
class Rhombus : public Shape {
private:
	int diagonal; // need to odd and >= 1
	virtual int getHeightBBox() const override;
	virtual int getWidthBBox() const override;
public:
	explicit Rhombus(const unsigned int& = 1, const string& = "Generic Rhombus");
	~Rhombus();
	virtual int getWidth() const override;
	virtual int getHeight() const override;
	int getDiagonal() const;
	void setDiagonal(const unsigned int&);
	virtual void scale(const int&) override;
	virtual double getGeoArea() const override;
	virtual int getScreenArea() const override;
	virtual double getGeoPerimeter() const override;
	virtual int getScreenPerimeter() const override;
	virtual vector<vector<char>> draw(char = '*', char = ' ') const override;
};

#endif