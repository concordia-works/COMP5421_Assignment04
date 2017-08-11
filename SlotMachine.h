#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include <array>
#include "Shape.h"
#include "Rhombus.h"
#include "Rectangle.h"
#include "Isosceles.h"
#include "RightTriangle.h"

using std::cout;
using std::cin;
using std::endl;
using std::array;

class SlotMachine
{
private:
	array<Shape*, 3> shape_reel;
	void displayTutorial() const;
	void make_shapes(); // make shape reels point at newly created dynamic shape objects
	void make_shape(int); // makes shape_reel[r] point to a newly created dynamic shape object
	void display_shapes() const; // display the shape reels
	void calculate_token();
	void report_status(); // display outcome, payout, and tokens left
	void release_shapes(); // free dynamic objects currently pointed at by the shape reels

	int result;
	int tokens;
	int bet;
	int randomInt(int = 1, int = 25) const;
	int max(int, int) const;
	ostream& write_image_to_stream(ostream&, const vector<vector<char>>&) const;
public:
	SlotMachine();
	void run();
	virtual ~SlotMachine();
};

#endif