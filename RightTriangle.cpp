#include "RightTriangle.h"

RightTriangle::RightTriangle(const unsigned int& base, const string& dName) : Triangle("RightTriangle", dName) {
	if (base >= 1) {
		this->base = base;
		this->height = this->base;
	}
	else
		throw "Invalid input: Base must be >= 1";
}

RightTriangle::~RightTriangle() {}

void RightTriangle::setBase(const unsigned int& base) {
	if (base >= 1) {
		this->base = base;
		this->height = this->base;
	}
	else
		throw "Invalid input: Base must be >= 1";
}

void RightTriangle::scale(const int& n) {
	if (base + n >= 1) {
		base += n;
		height = base;
	}
	else
		throw "Invalid input";
}

int RightTriangle::getScreenArea() const {
	return height * (height + 1) / 2;
}

double RightTriangle::getGeoPerimeter() const {
	return (2 + std::sqrt(2)) * height;
}

int RightTriangle::getScreenPerimeter() const {
	return 3 * (height - 1);
}

vector<vector<char>> RightTriangle::draw(char penChar, char fillChar) const {
	vector<vector<char>> grid(this->base, vector<char>(this->base, fillChar));
	for (int r = 0; r < grid.size(); r++) {
		for (int c = 0; c <= r; c++) {
			grid[r][c] = penChar;
		}
	}
	return grid;
}
