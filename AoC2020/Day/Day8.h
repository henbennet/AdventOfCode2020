#pragma once
#include "../stdafx.h"

struct instruction {
	instruction(int n, string i) {
		number = n;
		instr = i;
		visited = false;
	}
	int number;
	string instr;
	bool visited;
};

class Day8
{
public:
	void run();

private:
	vector<instruction> infinit;


	void taskOne();
	pair<int,int> runProgram();
	void parseFile(string filename);
	void taskTwo();
	void reset(int in, string stored);
};

