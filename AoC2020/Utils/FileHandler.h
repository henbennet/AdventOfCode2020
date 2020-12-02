#pragma once

#include "../stdafx.h"

using namespace std;

class FileHandler
{
public:
	static string readLine(string filename);
	static string readLine(string filename, int row);
	static string readFileToString(string filename);
	static string readFileToString(string filename, string delim);
	static vector<string> readFileVecStr(string filename);
	static vector<int> readFileVecInt(string filename);
	static vector<int> readFileVecInt_f(string filename);
};

