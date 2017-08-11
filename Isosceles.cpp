#include "Isosceles.h"

Isosceles::Isosceles(const unsigned int& base, const string& dName) : Triangle("Isosceles", dName) {
	if (base >= 1) {
		if (base % 2 != 0)
			this->base = base;
		else
			this->base = base + 1;
		this->height = (this->base + 1) / 2;
	}
	else
		throw "Invalid input: Base must be >= 1";
}

Isosceles::~Isosceles() {}

void Isosceles::setBase(const unsigned int& base) {
	if (base >= 1) {
		if (base % 2 != 0)
			this->base = base;
		else
			this->base = base + 1;
		this->height = (this->base + 1) / 2;
	}
	else
		throw "Invalid input: Base must be >= 1";
}

void Isosceles::scale(const int& n) {
	if (base + 2 * n >= 1) {
		base += 2 * n;
		height = (base + 1) / 2;
	}
	else
		throw "Invalid input";
}

int Isosceles::getScreenArea() const {
	return std::pow(height, 2);
}

double Isosceles::getGeoPerimeter() const {
	return base + 2 * std::sqrt(0.25 * std::pow(base, 2) + std::pow(height, 2));
}

int Isosceles::getScreenPerimeter() const {
	return 4 * (height - 1);
}

vector<vector<char>> Isosceles::draw(char penChar, char fillChar) const {
	vector<vector<char>> grid(this->height, vector<char>(this->base, fillChar));
	int padding = 0;
	for (int r = grid.size() - 1; r >= 0; r--) {
		for (int c = padding; c < grid[r].size() - padding; c++) {
			grid[r][c] = penChar;
		}
		padding++;
	}
	return grid;
}
