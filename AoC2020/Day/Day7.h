#pragma once
#include "../stdafx.h"
struct bag {
public:
	int no;
	string name;
};

class Day7
{
public:
	void run();

private:

	map<string, vector<pair<int,string>>> bagMap;

	void taskOne();
	void taskTwo();

	void populateBags(string);

	int countColors(string lookFor);
	int countBags(string lookFor);

	int searchRec(string lookFor, string inColor);



};

