#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <typeinfo>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::vector;

class Shape {
private:
	static int idSeed;
	int id;
	string gName;
	string dName;
protected:
	virtual int getWidthBBox() const = 0;
	virtual int getHeightBBox() const = 0;
public:
	Shape(const string&, const string&);
	int getID() const;
	string getGName() const;
	string getDName() const;
	void setDName(const string&);
	virtual ~Shape();
	virtual void scale(const int&) = 0;
	string toString() const;
	virtual double getGeoArea() const = 0;
	virtual int getScreenArea() const = 0;
	virtual double getGeoPerimeter() const = 0;
	virtual int getScreenPerimeter() const = 0;
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;
	virtual vector<vector<char>> draw(char = '*', char = ' ') const = 0;
	friend ostream& operator<<(ostream&, const Shape&);
	friend ostream& operator<<(ostream&, const vector<vector<char>>&);
	void draw_on_screen(char = '*', char = ' ') const;
	ostream& write_image_to_stream(ostream&, char = '*', char = ' ') const;
};

#endif