#include "Day1.h"
 
#include <iostream>
#include <chrono>


void Day1::run()
{

	auto begin = std::chrono::high_resolution_clock::now();
	taskTwo();
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	
	
	cout << elapsed.count()*1e-3 << endl;
}

void Day1::test()
{ 
	string str = FileHandler::readFile("./res/Day1Test.txt");
	vector<int> vector = StrHandler::splitInt(str, "([0-9]+)");
	cout << "Searching ..." << endl;
	for (int i = 0; i < vector.size(); i++) {
		//cout << i << ": ";
		for (int j = i; j < vector.size(); j++) {
			if ((vector.at(i) + vector.at(j)) == 2020) {
				cout << endl << endl;
				cout << vector.at(i) << " + " << vector.at(j) << " = " << vector.at(i) + vector.at(j) << endl;
				cout << vector.at(i) << " * " << vector.at(j) << " = " << vector.at(i) * vector.at(j) << endl;
				return;
			}
			//cout << j << " ";
		}
		//cout << endl;
	}
	cout << "Could not find" << endl;
	//cout << str << endl;
}

void Day1::taskOne()
{
	string str = FileHandler::readFile("./res/Day1a.txt");
	vector<int> vector = StrHandler::splitInt(str, "([0-9]+)");
	cout << "Searching ..." << endl;
	for (int i = 0; i < vector.size(); i++) {
		//cout << i << ": ";
		for (int j = i; j < vector.size(); j++) {
			if ((vector.at(i) + vector.at(j)) == 2020) {
				cout << endl << endl;
				cout << vector.at(i) << " + " << vector.at(j) << " = " << vector.at(i) + vector.at(j) << endl;
				cout << vector.at(i) << " * " << vector.at(j) << " = " << vector.at(i) * vector.at(j) << endl;
				return;
			}
			//cout << j << " ";
		}
		//cout << endl;
	}
	cout << "Could not find" << endl;
	//cout << str << endl;
}

void Day1::taskTwo()
{
	//string str = FileHandler::readFile("./res/Day1a.txt");
	//vector<int> vector = StrHandler::splitInt(str, "([0-9]+)");
	vector<int> vector = FileHandler::readFileVecInt("./res/Day1a.txt");

	//cout << "Searching ..." << endl;
	for (int i = 0; i < vector.size(); i++) {
		//cout << i << ": ";
		for (int j = i; j < vector.size(); j++) {
			for (int k = j; k < vector.size(); k++) {
				if ((vector.at(i) + vector.at(j) + vector.at(k)) == 2020) {
		//			cout << endl << endl;
		//			cout << vector.at(i) << " + " << vector.at(j) << " + " << vector.at(k) << " = " << vector.at(i) + vector.at(j) + vector.at(k) << endl;
					cout << vector.at(i) << " * " << vector.at(j) << " * " << vector.at(k) << " = " << vector.at(i) * vector.at(j) * vector.at(k) << endl;
					return;
				}
			}
			//cout << j << " ";
		}
		//cout << endl;
	}
	cout << "Could not find" << endl;
	//cout << str << endl;
}
