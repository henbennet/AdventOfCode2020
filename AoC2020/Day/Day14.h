#pragma once
#include "../stdafx.h"

class Day14
{
public:
	void run();
private:
	vector<string> file;
	
	void taskTest(string filename);
	void taskOne(string);
	void taskTwo(string);

	long long toDec(string bin);
	string toBin(int dec);

	void iterations(string adr, vector<string> *vec);
	vector<string> maskMem(string adr, string mask);
	string maskValue(string value, string mask);

	void print(vector<int> vec, string delim);
	void parse(string filename);
};

