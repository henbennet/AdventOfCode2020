#include "Day2.h"

void Day2::run()
{


	auto begin = std::chrono::high_resolution_clock::now();
	taskTwo();
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout << elapsed.count() * 1e-6 << endl;
	
}

void Day2::test()
{
	string filename = "Day2Test.txt";
}

void Day2::taskOne()
{
	string filename = "./res/Day2a.txt";
	//string filename = "./res/Day2Test.txt";
	vector<string> file = FileHandler::readFileVecStr(filename);
	int count = 0;

	for (string line : file) {
		int low;
		int high;
		char letter;

		sscanf_s(line.c_str(), "%d-%d %c:", &low, &high, &letter, 1);
		string password = StrHandler::splitWithDelim(line, ": ").back();

		size_t occ = StrHandler::countOccurrences(password, letter);

		if (occ >= low && occ <= high) {
			count++;
		}
	}
	cout << "number of correct pwd: " << count << endl;
}

void Day2::taskTwo()
{
	string filename = "./res/Day2a.txt";
	//string filename = "./res/Day2Test.txt";
	vector<string> file = FileHandler::readFileVecStr(filename);

	int count = 0;
	int count2 = 0;

	for (string line : file) {
		int low;
		int high;
		char letter;

		sscanf_s(line.c_str(), "%d-%d %c:", &low, &high, &letter);
		string password = StrHandler::splitWithDelim(line, ": ").back();

		//cout << low << " " << high  << " " << letter <<"|" <<password << "|" << endl;
		size_t occ = StrHandler::countOccurrences(password, letter);
		//cout << "low "<< low <<": " << password.at(low) << " high "<< high <<": " << password.at(high) << endl;

		if ((password.at(low) == letter) != (password.at(high) == letter)) {
			count2++;
		}
	}
	cout << "part two: " << count2 << endl;


}
