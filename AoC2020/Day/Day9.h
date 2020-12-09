#pragma once
#include "../stdafx.h"

class Day9
{
public:
	void run();

private:
	vector<double> file;

	void taskOne();
	void taskTwo();

	double max(int first, int last);
	double min(int first, int last);
	
	pair<int, int> findContiguousSet(double invalidNumber);
	double findInvalidNumber(int preamble);
	
};



/*
// 96779839 to high


*/