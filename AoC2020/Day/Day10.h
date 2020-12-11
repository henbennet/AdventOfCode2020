#pragma once
#include "../stdafx.h"

class Day10
{
public:
	void run();

private:
	vector<int> file;
	vector<int> jolt;
	double count;

	void taskOne(string);
	void taskTwo(string);

	void print();

	void stepThrough();

	void search(int index, int prevJolt);

	double recStep();

	double recStep(int index, vector<int> vec);

	double recursiveStepThrough(int index, int base);

};



/*
// 96779839 to high


*/