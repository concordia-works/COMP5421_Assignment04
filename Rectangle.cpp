#include "Rectangle.h"

int Rectangle::getWidthBBox() const {
	return width;
}

int Rectangle::getHeightBBox() const {
	return height;
}

Rectangle::Rectangle(const unsigned int& width, const unsigned int& height, const string& dName) : Shape("Rectangle", dName) {
	if ((width >= 1) && (height >= 1)) {
		this->width = width;
		this->height = height;
	}
	else
		throw "Invalid input: Width and Height must be >= 1";
}

Rectangle::~Rectangle() {}

int Rectangle::getWidth() const {
	return width;
}

int Rectangle::getHeight() const {
	return height;
}

void Rectangle::setWidth(const unsigned int& newWidth) {
	if (newWidth >= 1)
		width = newWidth;
	else
		throw "Invalid input: Width must be >= 1";
}

void Rectangle::setHeight(const unsigned int& newHeight) {
	if (newHeight >= 1)
		width = newHeight;
	else
		throw "Invalid input: Height must be >= 1";
}

void Rectangle::scale(const int& n) {
	if ((width + n >= 1) && (height + n >= 1)) {
		width += n;
		height += n;
	}
	else
		throw "Invalid input";
}

double Rectangle::getGeoArea() const {
	return (double) (height * width);
}

int Rectangle::getScreenArea() const {
	return getGeoArea();
}

double Rectangle::getGeoPerimeter() const {
	return 2 * (double) (height + width);
}

int Rectangle::getScreenPerimeter() const {
	return getGeoPerimeter() - 4;
}

vector<vector<char>> Rectangle::draw(char penChar, char fillChar) const {
	return vector<vector<char>>(this->height, vector<char>(width, penChar));
}
