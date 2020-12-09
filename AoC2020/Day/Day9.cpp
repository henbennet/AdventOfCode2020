#include "Day9.h"

void Day9::run()
{
	auto begin = std::chrono::high_resolution_clock::now();
	taskTwo();
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;

}

void Day9::taskOne()
{
	//string filename = "./res/Test.txt";
	string filename = "./res/Day9.txt";
	file = FileHandler::readFileVecDouble(filename);
	int preamble = 25;
	double invalidNumber = findInvalidNumber(preamble);
	cout << "Invalid number: " << fixed << invalidNumber << endl;
}

void Day9::taskTwo()
{
	//string filename = "./res/Test.txt";
	string filename = "./res/Day9.txt";
	file = FileHandler::readFileVecDouble(filename);
	int preamble = 25;
	double invalidNumber = findInvalidNumber(preamble);
	cout << "Invalid number: " << fixed << invalidNumber << endl;

	pair<int, int> set = findContiguousSet(invalidNumber);

	double setLarge = max(set.first, set.second);
	double setSmall = min(set.first, set.second);
	cout << "Encryption weeknes: " << fixed << setSmall << " + " << fixed << setLarge << " = " << fixed << setSmall+setLarge << endl;

}

double Day9::max(int first, int last) {
//double Day9::max(vector<double> vec) {
	double max = 0;
	for (int i=first; i <= last; i++) {
		if (file.at(i) > max) {
			max = file.at(i);
		}
	}
	return max;
}
double Day9::min(int first, int last) {
//double Day9::min(vector<double> vec) {
	double min = file.at(first);
	for (int i = first; i <= last; i++) {
		if (file.at(i) < min) {
			min = file.at(i);
		}
	}
	return min;
}

pair<int, int> Day9::findContiguousSet(double invalidNumber) {
//vector<double> Day9::findContiguousSet(double invalidNumber, vector<double> file) {
	int first = 0;
	int last = 0;
	vector<double> set;

	for (first; first < file.size();first++) {
		double setValue = 0;
		last = first;
		while (setValue <= invalidNumber && last<file.size()) {
			setValue += file.at(last);
			if (setValue == invalidNumber) {
				return { first, last };
				/*for (int i = first; i <= last; i++) {
					set.push_back(file.at(i));
				}
				return set;*/
			}
			last++;
		}
	}
	cout << "Could not find any contigous set" << endl;
	return { 0 ,0 };
}


double Day9::findInvalidNumber(int preamble) {
	double invalidNumber = -1;
	for (int index = preamble; index < file.size(); index++) {
		bool valid = false;
		for (int i = index - preamble; i < index; i++) {
			for (int j = i + 1; j < (index); j++) {
				if (i == j || file.at(i) == file.at(j)) {
					continue;
				}
				else if (file.at(i) + file.at(j) == file.at(index)) {
					valid = true;
					i = j = index;
				}
			}
		}
		if (!valid) {
			invalidNumber = file.at(index);
			break;
		}
	}
	return invalidNumber;
}