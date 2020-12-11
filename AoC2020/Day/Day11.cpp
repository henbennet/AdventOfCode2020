#include "Day11.h"


void Day11::run()
{
	auto begin = std::chrono::high_resolution_clock::now();
	string filename = "./res/Day11.txt";
	//string filename = "./res/Test.txt";
	taskTwo(filename);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;
}

void Day11::taskTest(string filename) {
	init(filename);
	print(current);
	cout << checkLOS(3, 3) << endl;
}
void Day11::taskOne(string filename)
{
	init(filename);
	print(current);
	int counter = 0;
	while (seatingPart1(4)) { counter++;  }
	print(current);
	cout << "Occupied seats ("<< counter <<") : " << count('#') << endl;
}

void Day11::taskTwo(string filename)
{
	init(filename);
	print(current);
	int counter = 0;
	//seatingPart2(5);
	while (seatingPart2(5)) { counter++; }
	print(current);

	cout << "Occupied seats (" << counter << ") : " << count('#') << endl;
}

void Day11::init(string filename) {
	current = FileHandler::readFileVecStr(filename);
	next = current;
}


bool Day11::seatingPart2(int acceptance) {
	bool changed = false;
	for (int row = 0; row < current.size(); row++) {
		for (int col = 0; col < current.at(row).size(); col++) {
			char c = current.at(row).at(col);
			int occ = checkLOS(row, col);
			if (c == '#' && occ >= acceptance) {
				next.at(row).at(col) = 'L';
				changed = true;
			}
			else if (c == 'L' && occ == 0) {
				next.at(row).at(col) = '#';
				changed = true;
			}
		}
	}
	current = next;
	return changed;
}

bool Day11::seatingPart1(int acceptance) {
	bool changed = false;;
	for (int row = 0; row < current.size(); row++) {
		for (int col = 0; col < current.at(row).size(); col++) {
			char c = current.at(row).at(col);
			int occ = checkAdjecent(row, col);
			if (c == '#' && occ >= acceptance) {
				next.at(row).at(col) = 'L';
				changed = true;
			}
			else if (c == 'L' && occ == 0) {
				next.at(row).at(col) = '#';
				changed = true;
			}
		}
	}
	current = next;
	return changed;
}

int Day11::checkLOS(int row, int col) {
	int count = 0;
	//O L L O L L O
	//L O L O L O L
	//L	L O O O L L
	//O	O O # O O O
	//L	L O O O L O
	//L	O L O L O L
	//O L L O L L O

	// +/- 1
	// +/- 2
	//-1, 0, 1

	for (int ri = -1; ri <= 1; ri++) {
		for (int ci = -1; ci <= 1; ci++) {
			if (ri == 0 && ci == 0) {
				continue;
			}
			for (int x = 1;
				((row + ri * x) >= 0 && 
					row + ri * x < current.size()) &&
				((col + ci * x) >= 0 && 
					col + ci * x < current.at(0).size())
				; x++) {
				int r = row + ri * x;
				int c = col + ci * x;
				if (current.at(r).at(c) == 'L') {
					break;
				}
				if (current.at(r).at(c) == '#') {
					count++;
					break;
				}
			}
		}
	}
	return count;
	/*
	for (int r = row+1; r < current.size(); r++) {
		if (current.at(r).at(col) == '#') {
			count++;
			break;
		}
	}
	for (int r = row - 1; r >= 0; r--) {
		if (current.at(r).at(col) == '#') {
			count++;
			break;
		}
	}
	for (int c = col + 1; c < current.at(row).size(); c++) {
		if (current.at(row).at(c) == '#') {
			count++;
			break;
		}
	}
	for (int c = col - 1; c < current.at(row).size(); c--) {
		if (current.at(row).at(c) == '#') {
			count++;
			break;
		}
	}	
	return count;
	*/
}

int Day11::checkAdjecent(int row, int col) {
	int count = 0;
	for (int r = row - 1; r <= row + 1 ; r++) {
		if (r >= 0 && r < current.size()) {
			for (int c = col - 1; c <= col + 1 ; c++) {
				if (c >= 0 && c < current.at(r).size()) {
					if (c == col && r == row) {
						continue;
					}
					if (current.at(r).at(c) == '#') {
						count++;
					}
				}
			}
		}
	}
	//cout << row << ", " << col << " : " << count << endl;
	return count;
}

int Day11::count(char find) {
	int count = 0;
	for (int r = 0; r < current.size(); r++) {
		for (int c = 0; c < current.at(r).size(); c++) {
			if (current.at(r).at(c) == find) {
				count++;
			}
		}
	}
	return count;
}

void Day11::print(vector<string> vec)
{	
	cout << endl;
	for (string str : vec) {
		cout << str << endl;
	}
	cout << endl;
}
