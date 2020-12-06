#include "Day6.h"

void Day6::run()
{
	auto begin = std::chrono::high_resolution_clock::now();
	taskTwo();
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;
}

void Day6::taskOne()
{
	string filename = "./res/Day6.txt";
	vector<string> file = FileHandler::readFileVecStr(filename);
	string group;
	int count = 0;
	for (string line : file) {
		if (line.length() > 0) {
			group.append(line);
		}
		else {
			count += countUnique(group);
			group.clear();
		}
	}
	count += countUnique(group);
	cout << "numb : " << count << endl;
}

void Day6::taskTwo()
{
	string filename = "./res/Day6.txt";
	vector<string> file = FileHandler::readFileVecStr(filename);
	//string group;
	vector<string> group;
	int count = 0;
	for (string line : file) {
		if (line.length() > 0) {
			group.push_back(line);
		}
		else {
			count += countSame(group);
			group.clear();
		}
	}
	count += countSame(group);
	cout << "numb : " << count << endl;
}
int Day6::countSame(vector<string> group) {
	if (group.size() <= 0) {
		return 0;
	}
	
	string uni = group.at(0);


	for (int x = 1; x < group.size(); x++) {
		string person = group.at(x);
		string new_uni;
		for (int y = 0; y < uni.size(); y++) {
			char c = uni.at(y);
			size_t pos = person.find(c);

			if (pos != string::npos) {
				new_uni += c;
			}
		}
		uni = new_uni;
	}
	return uni.size();
}

int Day6::countUnique(string group)
{
	string uni;

	for (int i = 0; i<group.size(); i++) {
		if (uni.find(group.at(i)) == string::npos) {
			uni += group.at(i);
		}
	}
    return uni.size();
}
 