#include "Rhombus.h"

int Rhombus::getHeightBBox() const {
	return diagonal;
}

int Rhombus::getWidthBBox() const {
	return diagonal;
}

Rhombus::Rhombus(const unsigned int& diagonal, const string& dName) : Shape("Rhombus", dName) {
	if (diagonal >= 1)
		if (diagonal % 2 != 0)
			this->diagonal = diagonal;
		else
			this->diagonal = diagonal + 1;
	else
		throw "Invalid input: Diagonal must be >= 1";
}

Rhombus::~Rhombus() {}

int Rhombus::getWidth() const {
	return getDiagonal();
}

int Rhombus::getHeight() const {
	return getDiagonal();
}

int Rhombus::getDiagonal() const {
	return diagonal;
}

void Rhombus::setDiagonal(const unsigned int& diagonal) {
	if (diagonal >= 1)
		if (diagonal % 2 != 0)
			this->diagonal = diagonal;
		else
			throw "Invalid input: Diagonal must be an odd number";
	else
		throw "Invalid input: Diagonal must be >= 1";
}

void Rhombus::scale(const int& n) {
	if (diagonal + 2 * n >= 1)
		diagonal += 2 * n;
	else
		throw "Invalid input";
}

double Rhombus::getGeoArea() const {
	return std::pow(diagonal, 2) / (double) 2;
}

int Rhombus::getScreenArea() const {
	int n = diagonal / 2;
	return 2 * n * (n + 1) + 1;
}

double Rhombus::getGeoPerimeter() const {
	return 2 * std::sqrt(2) * diagonal;
}

int Rhombus::getScreenPerimeter() const {
	return 2 * (diagonal - 1);
}

vector<vector<char>> Rhombus::draw(char penChar, char fillChar) const {
	vector<vector<char>> grid(this->diagonal, vector<char>(this->diagonal, fillChar));
	int padding = 0;
	for (int r = (grid.size() + 1) / 2 - 1; r >= 0; r--) {
		for (int c = padding; c < grid[r].size() - padding; c++) {
			grid[r][c] = penChar;
		}
		padding++;
	}

	padding = 1;
	for (int r = (grid.size() + 1) / 2; r < grid.size(); r++) {
		for (int c = padding; c < grid[r].size() - padding; c++) {
			grid[r][c] = penChar;
		}
		padding++;
	}
	return grid;
}
