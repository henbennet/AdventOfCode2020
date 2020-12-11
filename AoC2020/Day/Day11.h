#pragma once
#include "../stdafx.h"

class Day11
{
public:
	void run();

private:
	vector<string> current;
	vector<string> next;

	void taskTest(string filename);

	void taskOne(string);
	void taskTwo(string);

	void init(string);

	bool seatingPart1(int acceptance);
	bool seatingPart2(int acceptance);

	int checkLOS(int row, int col);
	int checkAdjecent(int row, int col);

	int count(char find);

	void print(vector<string>);

};
