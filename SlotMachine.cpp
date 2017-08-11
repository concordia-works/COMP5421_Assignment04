#include "SlotMachine.h"

void SlotMachine::displayTutorial() const {
	cout << "Welcome to this 3-Reel Slot Machine Game!" << endl;
	cout << "Each reel will randomly display one of four shapes, each in 25 sizes." << endl;
	cout << "To win 3 times your bet you need 3 similar shapes of the same size." << endl;
	cout << "To win 2 times your bet you need 3 similar shapes." << endl;
	cout << "To win or lose nothing you need 2 similar shapes." << endl;
	cout << "Otherwise, you lose your bet." << endl;
	cout << "You start with 10 free tokens!" << endl << endl;
}

void SlotMachine::make_shapes() {
	for (int r = 0; r <= 2; r++) {
		make_shape(r);
	}
}

void SlotMachine::make_shape(int r) {
	int n = randomInt(0, 4);
	int w = randomInt(1, 25);
	switch (n) {
	case 0:
		shape_reel[r] = new Rhombus(w);
		break;
	case 1:
		shape_reel[r] = new Isosceles(w);
		break;
	case 2:
		shape_reel[r] = new RightTriangle(w);
		break;
	case 3:
		int h = randomInt(1, 25);
		shape_reel[r] = new Rectangle(w, h);
		break;
	}
}

void SlotMachine::display_shapes() const {
	// Prepare the bounding box for all three shapes
	int bBoxWidth = 10;
	int bBoxHeight = 0;
	array<int, 3> reelsWidth;
	for (int i = 0; i <= 2; i++) {
		reelsWidth[i] = shape_reel[i]->getWidth();
		bBoxWidth += reelsWidth[i];
		bBoxHeight = max(bBoxHeight, shape_reel[i]->getHeight());
	}
	bBoxHeight += 2;
	vector<vector<char>> bBox(bBoxHeight, vector<char>(bBoxWidth));

	// Build the bounding box's border & separater
	for (int c = 0; c < bBoxWidth; c++) {
		bBox[0][c] = '-';
		bBox[bBoxHeight - 1][c] = '-';
	}
	for (int r = 0; r < bBoxHeight; r++) {
		bBox[r][0] = '|';
		bBox[r][bBoxWidth - 1] = '|';
	}
	bBox[0][0] = '+';
	bBox[bBoxHeight - 1][0] = '+';
	bBox[0][bBoxWidth - 1] = '+';
	bBox[bBoxHeight - 1][bBoxWidth - 1] = '+';
	int currCol = 0;
	array<int, 3> nextCol;
	for (int i = 0; i <= 2; i++) {
		nextCol[i] = currCol + reelsWidth[i] + 3;
		bBox[0][nextCol[i]] = '+';
		bBox[bBoxHeight - 1][nextCol[i]] = '+';
		currCol = nextCol[i];
	}
	for (int r = 1; r < bBoxHeight - 1; r++) {
		currCol = 0;
		for (int j = 0; j <= 2; j++) {
			currCol += reelsWidth[j] + 3;
			bBox[r][currCol] = '|';
		}
	}

	// Build the shapes
	for (int i = 0, startRow = 1; i <= 2; i++) {
		int startCol = nextCol[i] - (shape_reel[i]->getWidth() + 1);
		vector<vector<char>> shapeDraw = shape_reel[i]->draw();
		for (int r = startRow, sr = 0; sr < shapeDraw.size(); r++, sr++) {
			for (int c = startCol, sc = 0; sc < shapeDraw[sr].size(); c++, sc++) {
				bBox[r][c] = shapeDraw[sr][sc];
			}
		}
	}

	// Draw the bounding box
	write_image_to_stream(cout, bBox);

	for (int i = 0; i <= 2; i++) {
		cout << "(" << shape_reel[i]->getGName() << ", " << shape_reel[i]->getWidth() << ", " << shape_reel[i]->getHeight() << ") ";
	}
	cout << endl;
}

void SlotMachine::calculate_token() {
	/*
	** result means
	** 0: win or lose nothing
	** 1: never happen
	** 2: win 2 times the bet
	** 3: win 3 times the bet
	*/
	result = -1;
	if (shape_reel[0]->getGName().compare(shape_reel[1]->getGName()) == 0)
		result++;
	if (shape_reel[0]->getGName().compare(shape_reel[2]->getGName()) == 0)
		result++;
	if (shape_reel[1]->getGName().compare(shape_reel[2]->getGName()) == 0)
		result++;

	if (result == 2) {
		if ((shape_reel[0]->getWidth() == shape_reel[1]->getWidth() == shape_reel[2]->getWidth()) &&
			(shape_reel[0]->getHeight() == shape_reel[1]->getHeight() == shape_reel[2]->getHeight()))
			result++;
	}
}

void SlotMachine::report_status() {
	switch (result) {
	case -1:
		tokens -= bet;
		cout << "You lose your bet" << endl;
		break;
	case 0:
		cout << "You don't win, you don't lose, your are safe!" << endl;
		break;
	case 2:
		tokens += 2 * bet;
		cout << "Congratulations! you win 2 times your bet: " << 2 * bet << endl;
		break;
	case 3:
		tokens += 3 * bet;
		cout << "Congratulations! you win 3 times your bet: " << 3 * bet << endl;
		break;
	}
	cout << "You now have " << tokens << " tokens!" << endl << endl;
}

void SlotMachine::release_shapes() {
	for (int r = 0; r <= 2; r++)
		delete shape_reel[r];
}

int SlotMachine::randomInt(int from, int to) const {
	return rand() % to + from;
}

int SlotMachine::max(int lhs, int rhs) const {
	return (lhs > rhs) ? lhs : rhs;
}

ostream& SlotMachine::write_image_to_stream(ostream& out, const vector<vector<char>>& grid) const {
	for (int r = 0; r < grid.size(); r++) {
		for (int c = 0; c < grid[r].size(); c++) {
			out << grid[r][c];
		}
		out << endl;
	}
	return out;
}

SlotMachine::SlotMachine() {}

void SlotMachine::run() {
	tokens = 10;
	result = -1;
	displayTutorial();
	while (true) {
		if (tokens <= 0) {
			cout << "You have ran out of token!" << endl;
			cout << "Press ENTER to exit!";
			cin.ignore();
			cin.get();
			break;
		}

		// Step 1
		cout << "How much would you like to bet (enter 0 to quit)? ";
		cin >> bet;
		if (bet == 0) {
			cout << "Game Over. You now have " << tokens << " tokens!" << endl;
			cout << "Press ENTER to exit!";
			cin.ignore();
			cin.get();
			break;
		}
		else if (bet < 0) {
			continue;
		}

		// Step 2
		make_shapes();

		// Step 3
		display_shapes();

		// Step 3.1
		calculate_token();

		// Step 4
		report_status();

		// Step 5
		release_shapes();
	}
}

SlotMachine::~SlotMachine() {}
