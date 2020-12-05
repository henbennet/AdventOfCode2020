#include "Day5.h"

void Day5::run()
{
	auto begin = std::chrono::high_resolution_clock::now();
	taskTwo();
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;
}

void Day5::taskOne()
{
	rowLow = 0;
	rowHigh = 127;
	colLow = 0;
	colHigh = 7;
	int high = 0;

	string filename = "./res/Day5.txt";
	vector<string> vec = FileHandler::readFileVecStr(filename);
	//vec.push_back("FFFBBBFRRR");
	for (string pass : vec) {
		rowLow = 0;
		rowHigh = 127;
		colLow = 0;
		colHigh = 7;
		
		int id = search(pass);
		high = (id > high) ? id : high;
	}

	cout << high << endl;
}
//932
void Day5::taskTwo()
{
	string filename = "./res/Day5.txt";
	vector<string> vec = FileHandler::readFileVecStr(filename);

	vector<bool> seats;
	seats.resize(128 * 8);
	fill(seats.begin(), seats.end(), false);
	for (string pass : vec) {
		rowLow = 0;
		rowHigh = 127;
		colLow = 0;
		colHigh = 7;

		seats.at(search(pass)) = true;
	}
	
	for (int i = 1; i < seats.size() - 1; i++) {
		if (!seats.at(i) && seats.at(i - 1) && seats.at(i + 1)) {
			cout << "Seat: " << i << endl;
		}
	}
}


int Day5::search(string pass) {
	if (pass.length() > 0) {
		char c = pass.at(0);
		
		if (c == 'F'){
			rowHigh = rowHigh - (rowHigh+1 - rowLow) / 2;
		}
		else if (c == 'B'){
			rowLow = rowLow + (rowHigh+1 - rowLow) / 2;
		}
		else if (c == 'L'){
			colHigh = colHigh - (colHigh+1 - colLow) / 2;
		}
		else if (c == 'R'){
			colLow = colLow + (colHigh+1 - colLow) / 2;
		}
		//cout << c << endl;
	}
	else {
		//cout << "row: " << rowLow << " col: " << colLow << endl;
		return rowLow * 8 + colLow;
	}
	return search(pass.substr(1, pass.length()));
}