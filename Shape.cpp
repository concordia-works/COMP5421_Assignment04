#include "Shape.h"

int Shape::idSeed = 0;

Shape::Shape(const string& gName, const string& dName) {
	id = ++idSeed;
	this->gName = gName;
	this->dName = dName;
}

int Shape::getID() const {
	return this->id;
}

string Shape::getGName() const {
	return this->gName;
}

string Shape::getDName() const {
	return this->dName;
}

void Shape::setDName(const string& dName) {
	this->dName = dName;
}

Shape::~Shape() {}

string Shape::toString() const {
	std::ostringstream oss;
	oss << std::setprecision(2) << std::fixed;
	oss << "Shape Information" << endl;
	oss << "-----------------" << endl;
	oss << std::setw(15) << std::left << "Static type:" << typeid(this).name() << endl;
	oss << std::setw(15) << std::left << "Dynamic type:" << typeid(*this).name() << endl;
	oss << std::setw(15) << std::left << "Generic name:" << gName << endl;
	oss << std::setw(15) << std::left << "Description:" << dName << endl;
	oss << std::setw(15) << std::left << "id:" << id << endl;
	oss << std::setw(15) << std::left << "B. box width:" << getWidthBBox() << endl;
	oss << std::setw(15) << std::left << "B. box height:" << getHeightBBox() << endl;
	oss << std::setw(15) << std::left << "Scr area:" << getScreenArea() << endl;
	oss << std::setw(15) << std::left << "Geo area:" << getGeoArea() << endl;
	oss << std::setw(15) << std::left << "Scr perimeter:" << getScreenPerimeter() << endl;
	oss << std::setw(15) << std::left << "Geo perimeter:" << getGeoPerimeter() << endl;
	return oss.str();
}

void Shape::draw_on_screen(char penChar, char fillChar) const {
	cout << this->draw(penChar, fillChar) << endl;
}

ostream& operator<<(ostream & out, const Shape& rhs) {
	return out << rhs.toString();
}

ostream& operator<<(ostream& out, const vector<vector<char>>& grid) {
	for (size_t r = 0; r < grid.size(); r++) {
		for (size_t c = 0; c < grid[r].size(); c++) {
			out << grid[r][c];
		}
		out << endl;
	}
	return out;
}

ostream& Shape::write_image_to_stream(ostream& out, char penChar, char fillChar) const {
	return out << this->draw(penChar, fillChar);
}
