#include "Day13.h"

void Day13::run()
{
	auto begin = std::chrono::high_resolution_clock::now();
	//string filename = "./res/Day13.txt";
	string filename = "./res/Test.txt";
	taskOne(filename);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;
}

void Day13::taskTest(string filename)
{
}

void Day13::taskOne(string filename)
{
	vector<string> file = FileHandler::readFileVecStr(filename);


	cout << endl;
}

void Day13::taskTwo(string filename)
{
	vector<string> file = FileHandler::readFileVecStr(filename);


	cout << endl;
}


void Day13::print() {

}
