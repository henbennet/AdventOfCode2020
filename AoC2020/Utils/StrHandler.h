#pragma once
#include "../stdafx.h"

using namespace std;

class StrHandler
{
public:
	static vector<string> split(string input, string regex);
	static vector<string> splitWithDelim(string input, string delim);
	static vector<int> splitInt(string input, string regex);

	static size_t countOccurrences(string str, char find);

};

