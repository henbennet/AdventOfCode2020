#pragma onc

#include "../stdafx.h";

class Day5
{
public:
	void run();

private:
	Matrix seats;
	int rowHigh;
	int rowLow;
	int colHigh;
	int colLow;

	
	void taskOne();
	void taskTwo();
	int search(string);


};

