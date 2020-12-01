#pragma once
#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class StrHandler
{
public:
	static vector<string> split(string input, string regex);
	static vector<int> splitInt(string input, string regex);

};

